/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:31 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 15:00:57 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **env, char **option)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	option++;
	while (*option)
	{
		if (ft_strchr(*option, '-') != NULL)
		{
			ft_putstr_fd("unset: '", STDERR_FILENO);
			ft_putstr_fd(*option, STDERR_FILENO);
			ft_putstr_fd("' :not a valid identifier: \n", STDERR_FILENO);
			exit_status = EXIT_FAILURE;
		}
		ft_unsetenv(env, *option);
		option++;
	}
	return (exit_status);
}
