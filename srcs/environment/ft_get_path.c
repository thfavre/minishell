/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:17:45 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 18:35:21 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_path(t_minishell *ms)
{
	char	**all_path;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ms->env[i] != NULL)
	{
		if (ft_strncmp(ms->env[i], "PATH=", 5) == 0)
		{
			str = ft_calloc(ft_strlen(ms->env[i]) + 1, sizeof(char));
				if (!str)
					return (NULL);
				while (j < ft_strlen(ms->env[i]))
				{
					str[j] = ms->env[i][j];
					j++;
				}
		}
		i++;
	}
	all_path = ft_split(str + 5, ':');
	free(str);
	return (all_path);
}
