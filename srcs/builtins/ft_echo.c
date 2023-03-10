/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/11 00:49:45 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(char **option)
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

}
