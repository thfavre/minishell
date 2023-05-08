/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:53:34 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:53:36 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char **env, char *key)
{
	size_t	i;
	size_t	key_end_index;

	i = 0;
	if (ft_strcmp(key, "?") == 0)
		return (ft_itoa(g_last_exit_status));
	while (env && env[i])
	{
		key_end_index = 0;
		while (env[i][key_end_index] && env[i][key_end_index] != '=')
			key_end_index++;
		if (ft_strlen(key) != key_end_index || env[i][key_end_index] == '\0')
		{
			i++;
			continue ;
		}
		else if (ft_strncmp(env[i], key, key_end_index) == 0)
			return (env[i] + key_end_index + 1);
		i++;
	}
	return (ft_calloc(1, 1));
}
