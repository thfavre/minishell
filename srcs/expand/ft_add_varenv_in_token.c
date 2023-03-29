/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_varenv_in_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:26:09 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/28 14:13:14 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void		ft_add_varenv_in_list(t_list_token *token, char **venv);
t_list_venv	*ft_getwords_venv(char *word, char **venv);
char		*ft_getword_nodollars(char **str);
t_list_venv	*ft_getwords_dollars(char **str, char ***venv);
void		ft_join_word_venv(t_list_venv *lst);
char		*ft_get_one_word_venv(char ***venv);
char		*ft_getword_space_venv(char ***venv);
int			ft_lenword_nodollars(char *str);
int			ft_lenword_venv(char *str);
int			ft_lenword_venv_space(char *str);
t_list_venv	*ft_lstnew_venv(char *word);
void		ft_lstadd_back_venv(t_list_venv **lst, t_list_venv *nw);
void		ft_lastadd_middle_token(t_list_token *lst, t_list_token *nw);

void	ft_add_varenv_in_token(t_list_token *token, char **env)
{
	size_t	i;
	size_t	nb_venv;
	char	*name_venv;
	char	**var_env;
	
	var_env = ft_calloc(sizeof(char *), ft_nbr_varenv(token->word) + 1);
	//	TODO check error malloc
	i = 0;
	nb_venv = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
		{
			i++;
			name_venv = ft_get_name_varenv(&token->word[i]);
			var_env[nb_venv] = ft_getenv(env, name_venv);
			if (var_env[nb_venv] == NULL)
				break ;
			nb_venv++;
			free(name_venv);
		}
		else
			i++;
	}
	ft_add_varenv_in_list(token, var_env);
	free(var_env);
}

void	ft_add_varenv_in_list(t_list_token *token, char **venv)
{
	t_list_venv	*add_in;
	t_list_venv	*init;

	init = ft_getwords_venv(token->word, venv);
	add_in = init;
	free(token->word);
	token->word = init->word;
	if (add_in->next != NULL)
	{
		while (add_in != NULL)
		{
			if (add_in->next == NULL)
				break ;
			add_in = add_in->next;
		}
		while (add_in != init)
		{
			ft_lastadd_middle_token(token, ft_lstnew_token(add_in->word));
			add_in = add_in->previous;
		}
	}
	//free(init) and his word
}

t_list_venv	*ft_getwords_venv(char *word, char **venv)
{
	t_list_venv *create;

	if (*word != '$')
		create = ft_lstnew_venv(ft_getword_nodollars(&word));
	else
		create = ft_getwords_dollars(&word, &venv);
	while (*word != '\0')
	{
		if (*word != '$')
			ft_lstadd_back_venv(&create, \
					ft_lstnew_venv(ft_getword_nodollars(&word)));
		else
			ft_lstadd_back_venv(&create, ft_getwords_dollars(&word, &venv));
	}
	ft_join_word_venv(create);
	return (create);
}

void	ft_join_word_venv(t_list_venv *lst)
{
	t_list_venv	*tmp;
	char		*new_word;
	int			i;
	int			j;

	while (lst != NULL)
	{
		if (lst->next != NULL && *lst->word != ' ' && *lst->next->word != ' ')
		{
			i = 0;
			j = 0;
			new_word = ft_calloc(sizeof(char), \
				ft_strlen(lst->word) + ft_strlen(lst->next->word) + 1);
			//	TODO check malloc error
			while (lst->word[i] != '\0')	// TODO need to replace by strcat
			{
				new_word[j] = lst->word[i];
				i++;
				j++;
			}
			i = 0;
			while (lst->next->word[i] != '\0')	// TODO need to replace by strcat
			{
				new_word[j] = lst->next->word[i];
				i++;
				j++;
			}
			free(lst->word);
			lst->word = new_word;
			tmp = lst->next;
			lst->next = tmp->next;
			free(tmp->word);
			free(tmp);
		}
		else
			lst = lst->next;
	}
}

char	*ft_getword_nodollars(char **str)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_nodollars(*str) + 1);
	if (!word)
		return (NULL);
	while (**str != '\0')
	{
		word[i] = (**str);
		i++;
		(*str)++;
		if (**str == '$')
			break ;
	}
	return (word);
}

t_list_venv	*ft_getwords_dollars(char **str, char ***venv)
{
	t_list_venv	*create;
	char		*word;
	
	if (***venv != ' ')
	{
		word = ft_get_one_word_venv(venv);
		if (!word)
			return (NULL);
		create = ft_lstnew_venv(word);
		free(word);
	}
	else
	{
		word = ft_getword_space_venv(venv);
		if (!word)
			return (NULL);
		create = ft_lstnew_venv(word);
		free(word);
	}
	while (***venv != '\0')
	{
		if (***venv != ' ')
		{
			word = ft_get_one_word_venv(venv);
			if (!word)
				return (NULL);
			ft_lstadd_back_venv(&create, ft_lstnew_venv(word));
			free(word);
		}
		else
		{
			word = ft_getword_space_venv(venv);
			if (!word)
				return (NULL);
			ft_lstadd_back_venv(&create, ft_lstnew_venv(word));
			free(word);
		}
	}
	while (**str != '\0')
	{
		(*str)++;
		if (**str == '$')
			break ;
	}
	(*venv)++;
	return (create);
}

char	*ft_get_one_word_venv(char ***venv)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_venv(**venv) + 1);
	if (!word)
		return (NULL);
	while (***venv != '\0')
	{
		word[i] = ***venv;
		(**venv)++;
		i++;
		if (***venv == ' ')
			break ;
	}
	return (word);
}

char	*ft_getword_space_venv(char ***venv)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_venv_space(**venv) + 1);
	if (!word)
		return (NULL);
	while (***venv == ' ')
	{
		word[i] = ***venv;
		(**venv)++;
		i++;
	}
	return (word);
}

int	ft_lenword_nodollars(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '$')
			break ;
		len++;
	}
	return (len);
}

int	ft_lenword_venv(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == ' ')
			break ;
		len++;
	}
	return (len);
}

int	ft_lenword_venv_space(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] != ' ')
			break ;
		len ++;
	}
	return (len);
}

t_list_venv	*ft_lstnew_venv(char *word)
{
	t_list_venv	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(t_list_venv));
	if (!new)
		return (NULL);
	new->word = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	if (!new->word)
		return (NULL);
	while (word[i] != '\0')
	{
		new->word[i] = word[i];
		i++;
	}
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	ft_lstadd_back_venv(t_list_venv **lst, t_list_venv *nw)
{
	t_list_venv	*node;

	node = *lst;
	if (node == NULL)
		node = nw;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = nw;
		nw->previous = node;
	}
}

void	ft_lastadd_middle_token(t_list_token *lst, t_list_token *nw)
{
	nw->next = lst->next;
	lst->next = nw;
}
