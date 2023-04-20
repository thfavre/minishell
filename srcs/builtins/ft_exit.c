/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/04/20 13:24:38 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *ms, char **option)
{
	int	exit_status;

	ft_close(ms);
	if (option[1] == NULL)
		exit_status = g_last_exit_status;
	else if (ft_isnumber(option[1]))
		exit_status = ft_atoi(option[1]);
	else
	{
		ft_putstr_fd(option[1], STDERR_FILENO);
		ft_putstr_fd(" :numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	if (exit_status < 0)
		exit_status = -exit_status;
	exit(exit_status % 256);
}
