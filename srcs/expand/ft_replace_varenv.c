/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_varenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:26:14 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/05 16:19:03 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_replace_varenv(t_list_token *token, char **env, size_t i)
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
	token->word = ft_get_new_word(token->word, var_env);
	free(var_env);
	return (0);
}

void	ft_strcat_expand(char *s1, char *s2, size_t *i, size_t *j)
{
	s1[(*j)] = s2[(*i)];
	(*i)++;
	(*j)++;
}

void	ft_put_new_word(char *var_env, char *new_word, size_t *i, size_t *j)
{
	size_t	save;

	save = (*i) + 1;
	(*i) = 0;
	if (var_env != NULL)
	{
		while (var_env[(*i)] != '\0')
			ft_strcat_expand(new_word, var_env, i, j);
	}
	(*i) = save;
	(*i)++;
}

char	*ft_get_new_word(char *w, char **var_env)
{
	char	*new_word;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	new_word = ft_calloc(sizeof(char), ft_len_new_word(w, var_env) + 1);
	if (!new_word)
		return (NULL);
	while (w[i] != '\0')
	{
		if (w[i] == '$')
		{
			ft_put_new_word(var_env[k], new_word, &i, &j);
			k++;
			while (w[i] != '"' && w[i] != ' ' && w[i] != '$' && w[i] != '\0')
				i++;
		}
		else
			ft_strcat_expand(new_word, w, &i, &j);
	}
	free(w);
	return (new_word);
}

int	ft_len_new_word(char *w, char **var_env)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (w[i] != '\0')
	{
		if (w[i] == '$')
		{
			if (var_env[j] != NULL)
				count += ft_strlen(var_env[j]);
			j++;
			i++;
			while (w[i] != '"' && w[i] != ' ' && w[i] != '$' && w[i] != '\0')
				i++;
		}
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}
