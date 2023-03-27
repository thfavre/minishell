/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/23 15:56:49 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_echo(char **option)
{
	bool	newline;

	option++; // skip the command name
	newline = true;
	if (*option && ft_strcmp(*option, "-n") == 0)
	{
		newline = false;
		option++;
	}
	while (*option)
	{
		ft_putstr_fd(*option, 1);
		if (*(option + 1))
			ft_putchar_fd(' ', 1);
		option++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (EXIT_SUCCESS);
}
