/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_varenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:59:30 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/08 17:27:50 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"

void	ft_replace_varenv(t_list_token *token, char **env)
{
	size_t	i;
	size_t	nb_venv;
	char	*name_env;
	char	**var_env;

	i = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
			nb_venv++;
		i++;
	}
	var_env = ft_calloc(sizeof(char *), nb_env + 1);
	//check error malloc
	nb_venv = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
		{
			name_env = ft_get_name_varenv(&token->word[i]);
			var_env[nb_venv] = ft_getenv(env, name_env);
			nb_venv++;
			free(name_env);
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

	i = 0;
	j = 0;
	while (word[i] != '\0')
	{
		//add word and var_env in new_word
	}
}
