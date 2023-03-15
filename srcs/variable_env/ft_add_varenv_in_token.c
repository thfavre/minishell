
#include "minishell.h"

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
			nb_venv++;
			free(name_venv);
		}
		i++;
	}
	ft_add_varenv_in_list(token, var_env);
	free(var_env);
}

void	ft_add_varenv_in_list(t_list_token *token, char **venv)
{
	t_list_venv	*add_in;
	t_list_venv	*init;
	char		*word;
	char		**cpy;

	cpy = venv;
	word = token->word;
	init = ft_lstnew_venv(ft_getword_venv(&word, &cpy));
	while (*word != '\0')
		ft_lstadd_back_venv(&init, ft_lstnew_venv(ft_getword_venv(&word, &cpy)));
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
}

char	*ft_getword_venv(char **str, char ***venv)
{
	char	*word;

	if (**str == ' ')
		word = ft_getword_space(str);
	else if (**str != '$')
		word = ft_getword_nodollars(str);
	else
		word = ft_getword_dollars(str, venv);
	return (word);
}

char	*ft_getword_nodollars(char **str)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_nodollars(*str) + 1);
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

char	*ft_getword_dollars(char **str, char ***venv)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_strlen(**venv) + 1);
	while (***venv != '\0')
	{
		word[i] = ***venv;
		i++;
		(**venv)++;
	}
	(*venv)++;
	if (**str == '$')
		(*str)++;
	while (**str != '\0' && **str != '$')
	{
		(*str)++;
	}
	return (word);
}

t_list_venv	*ft_lstnew_venv(char *word)
{
	t_list_venv	*new;

	new = malloc(sizeof(t_list_venv));
	if (!new)
		return (NULL);
	new->word = word;
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
