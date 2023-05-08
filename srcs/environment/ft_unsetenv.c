/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:01:28 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 15:01:54 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv(char **env, char *key)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(key);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], key, len) == 0 && \
			(env[i][len] == '=' || env[i][len] == '\0'))
		{
			j = i;
			while (env[j] != NULL)
			{
				if (env[j] != NULL)
					free(env[j]);
				if (env[j + 1] != NULL)
					env[j] = ft_strdup(env[j + 1]);
				else
					env[j] = NULL;
				j++;
			}
		}
		i++;
	}
}
