/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:45:16 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:47:55 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **env)
{
	int	i;

	if (!env)
		return (EXIT_FAILURE);
	i = 0;
	while (env && env[i])
	{
		if (ft_strchr(env[i], '=') != NULL)
			printf("%s\n", env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
