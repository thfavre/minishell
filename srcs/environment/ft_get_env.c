/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:42:15 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 10:56:37 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_env(char **env)
{
	char	**all;
	size_t	size_env;
	size_t	i;

	size_env = 0;
	while (env[size_env] != NULL)
		size_env++;
	all = ft_calloc(sizeof(char *), size_env + 1);
	if (!all)
		return (NULL);
	size_env = 0;
	i = 0;
	while (env[size_env] != NULL)
	{
		all[size_env] = ft_calloc(sizeof(char), ft_strlen(env[size_env]) + 1);
		while (env[size_env][i] != '\0')
		{
			all[size_env][i] = env[size_env][i];
			i++;
		}
		i = 0;
		size_env++;
	}
	return (all);
}
