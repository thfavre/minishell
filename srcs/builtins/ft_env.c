/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:45:16 by thomas            #+#    #+#             */
/*   Updated: 2023/03/13 14:32:35 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **env)
{
	int	i;

	// if (!env)
	// 	return;
	i = 0;
	while (env && env[i]) // TODO if '=' in line
	{
		if (ft_strchr(env[i], '=') != NULL)
			printf("%s\n", env[i]);
		i++;
	}
}
