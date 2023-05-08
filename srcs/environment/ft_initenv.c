/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:53:14 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:53:17 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_initenv(char **env)
{
	char	**all;
	size_t	env_size;
	size_t	i;

	env_size = 0;
	while (env[env_size] != NULL)
		env_size++;
	all = ft_calloc(sizeof(char *), env_size + 1);
	if (!all)
		return (NULL);
	i = 0;
	while (i < env_size)
	{
		all[i] = ft_strdup(env[i]);
		if (!all[i])
			return (ft_free_env(all));
		i++;
	}
	return (all);
}
