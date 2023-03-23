/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/23 15:55:08 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_exit(t_minishell *ms, int exit_code)
{
	(void)ms;
	ft_close(ms);
	ft_putstr_fd("exit\n", 1); // TODO in on STDERROR or STDOUT fd ?
	if (exit_code < 0)
		exit(-exit_code)
	exit(exit_code);
}
