/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:41:03 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 10:57:02 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_varenv_heredoc(char **str, t_minishell *ms)
{
	size_t	i;
	size_t	nb_venv;
	char	*name_venv;
	char	**var_env;

	var_env = ft_calloc(sizeof(char *), ft_nbr_varenv((*str)) + 1);
	if (!var_env)
		exit(printf("Malloc Error\n"));
	i = 0;
	nb_venv = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '$')
		{
			name_venv = ft_get_name_varenv(&(*str)[++i]);
			var_env[nb_venv++] = ft_getenv(ms->env, name_venv);
			if (var_env[nb_venv - 1] == NULL)
				break ;
			free(name_venv);
		}
		else
			i++;
	}
	(*str) = ft_get_new_word_heredoc((*str), var_env, 0);
	free(var_env);
}

void	ft_strcat_expand_heredoc(char *s1, char *s2, size_t *i, size_t *j)
{
	s1[(*j)] = s2[(*i)];
	(*i)++;
	(*j)++;
}

void	ft_put_new_word_hd(char *var_env, char *new_word, size_t *i, size_t *j)
{
	size_t	save;

	save = (*i) + 1;
	(*i) = 0;
	if (var_env != NULL)
	{
		while (var_env[(*i)] != '\0')
			ft_strcat_expand_heredoc(new_word, var_env, i, j);
	}
	(*i) = save;
	(*i)++;
}

char	*ft_get_new_word_heredoc(char *w, char **var_env, size_t i)
{
	char	*new_word;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	new_word = ft_calloc(sizeof(char), ft_len_new_word_hd(w, var_env, 0) + 1);
	if (!new_word)
		return (NULL);
	while (w[i] != '\0')
	{
		if (w[i] == '$')
		{
			ft_put_new_word_hd(var_env[k], new_word, &i, &j);
			k++;
			while (w[i] != '"' && w[i] != ' ' && w[i] != '$' && \
					w[i] != '\0' && w[i] != '\n')
				i++;
		}
		else
			ft_strcat_expand_heredoc(new_word, w, &i, &j);
	}
	free(w);
	return (new_word);
}

int	ft_len_new_word_hd(char *w, char **var_env, int i)
{
	int	count;
	int	j;

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
			while (w[i] != '"' && w[i] != ' ' && w[i] != '$' && w[i] != '\0' \
					&& w[i] != '\n')
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
