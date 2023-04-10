/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_varenv_in_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:26:09 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 16:52:12 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_varenv_in_token(t_list_token *token, char **env, size_t i)
{
	size_t	nb_venv;
	char	*name_venv;
	char	**var_env;

	var_env = ft_calloc(sizeof(char *), ft_nbr_varenv(token->word) + 1);
	if (!var_env)
		return (1);
	i = 0;
	nb_venv = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
		{
			name_venv = ft_get_name_varenv(&token->word[++i]);
			var_env[nb_venv++] = ft_getenv(env, name_venv);
			if (var_env[nb_venv - 1] == NULL)
				break ;
			free(name_venv);
		}
		else
			i++;
	}
	ft_add_varenv_in_list(token, var_env);
	free(var_env);
	return (0);
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
	ft_free_init(init);
}

t_list_venv	*ft_getwords_venv(char *word, char **venv)
{
	t_list_venv	*create;

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
	char		*new_word;
	size_t		i;
	size_t		j;

	while (lst != NULL)
	{
		if (lst->next != NULL && *lst->word != ' ' && *lst->next->word != ' ')
		{
			i = 0;
			j = 0;
			new_word = ft_calloc(sizeof(char), \
				ft_strlen(lst->word) + ft_strlen(lst->next->word) + 1);
			while (lst->word[i] != '\0')
				ft_strcat_expand(new_word, lst->word, &i, &j);
			i = 0;
			while (lst->next->word[i] != '\0')
				ft_strcat_expand(new_word, lst->next->word, &i, &j);
			ft_free_excess(lst, new_word);
		}
		else
			lst = lst->next;
	}
}

void	ft_free_excess(t_list_venv *lst, char *new_word)
{
	t_list_venv	*tmp;

	free(lst->word);
	lst->word = new_word;
	tmp = lst->next;
	lst->next = tmp->next;
	free(tmp->word);
	free(tmp);
}
