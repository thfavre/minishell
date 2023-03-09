/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_varenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:59:30 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/09 14:31:33 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	*ft_get_new_word(char *word, char **var_env);
int	ft_len_new_word(char *word, char **var_env);

void	ft_replace_varenv(t_list_token *token, char **env)
{
	size_t	i;
	size_t	nb_venv = 0;
	char	*name_venv;
	char	**var_env;

	i = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
			nb_venv++;
		i++;
	}
	var_env = ft_calloc(sizeof(char *), nb_venv + 1);
	//check error malloc
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
	token->word = ft_get_new_word(token->word, var_env);
}

char	*ft_get_new_word(char *word, char **var_env)
{
	char	*new_word;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	save;

	i = 0;
	j = 0;
	k = 0;
	new_word = ft_calloc(sizeof(char), ft_len_new_word(word, var_env) + 1);
	while (word[i] != '\0')
	{
		if (word[i] == '$')
		{
			save = i;
			i = 0;
			while (var_env[k][i] != '\0')
			{
				new_word[j] = var_env[k][i];
				i++;
				j++;
			}
			k++;
			i = save;
			while (word[i] != '\0' && word[i] != ' ' && word[i] != '$')
				i++;
		}
		else
		{
			new_word[j] = word[i];
			i++;
			j++;
		}
	}
	free(word);
	return (new_word);
}

int	ft_len_new_word(char *word, char **var_env)
{
	int	count;
	int	i;
	int	j;
	int	k = 0;

	i = 0;
	j = 0;
	count = 0;
	while (word[i] != '\0')
	{
		if (word[i] == '$')
		{
			while (var_env[j][k] != '\0')
			{
				printf("{%c}", var_env[j][k]);
				k++;
				count++;
			}
			k = 0;
			j++;
			while (word[i] != '\0' && word[i] != ' ' && word[i] != '$')
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
