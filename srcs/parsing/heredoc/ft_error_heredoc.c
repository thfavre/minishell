/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:07:55 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/05 17:40:36 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_eof_heredoc(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int	ft_error_heredoc(t_minishell *ms, int code_error)
{
	if (code_error == 1)
		ft_putstr_fd("minishell: parse error near <<\n", 2);
	else
	{
		ft_putstr_fd("minishell: syntax error near unexpected token", 2);
		ft_putstr_fd(" `newline'\n", 1);
	}
	ms->syntax = 1;
	g_last_exit_status = 258;
	return (1);
}
