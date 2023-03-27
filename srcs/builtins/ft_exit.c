/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/27 14:58:21 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *ms, char **option)
{
	(void)ms;
	int exit_status;

	ft_close(ms);
	if (option[1] == NULL)
		exit_status = last_exit_status;
		// exit_status = ms->last_exit_status;
	else if (ft_isnumber(option[1]))
		exit_status = ft_atoi(option[1]);
	else
	{
		ft_putstr_fd(option[1], 2);
		ft_putstr_fd(" :numeric argument required\n", 2); // TODO in on STDERROR or STDOUT
		exit(255);
	}
	if (exit_status < 0)
		exit_status = -exit_status;
	exit(exit_status%256);
}
