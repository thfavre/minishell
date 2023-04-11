/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:06:48 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 15:06:58 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_signals_execution(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		g_last_exit_status = 128 + SIGINT;
	}
	else if (signo == SIGQUIT)
	{
		ft_putstr_fd("Quit: ", 1);
		ft_putnbr_fd(SIGQUIT, 1);
		ft_putstr_fd("\n", 1);
		g_last_exit_status = 128 + SIGQUIT;
	}
}

void	ft_handle_signals_prompt(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_last_exit_status = 1;
	}
	else if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}
