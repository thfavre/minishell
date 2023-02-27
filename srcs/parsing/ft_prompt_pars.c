/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:05:39 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/22 16:12:41 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_token(char *str)
{
	if (ft_strcmp(str, INFILE) == 0)
		return (1);
	else if (ft_strcmp(str, OUTFILE) == 0)
		return (1);
	else if (ft_strcmp(str, PIPE) == 0)
		return (1);
	else if (ft_strcmp(str, INFILE2) == 0)
		return (1);
	else if (ft_strcmp(str, OUTFILE2) == 0)
		return (1);
	return (0);
}

int	ft_is_builtins(char *str)
{
	if (ft_strcmp(str, ECHO) == 0)
		return (1);
	else if (ft_strcmp(str, CD) == 0)
		return (1);
	else if (ft_strcmp(str, PWD) == 0)
		return (1);
	else if (ft_strcmp(str, EXPORT) == 0)
		return (1);
	else if (ft_strcmp(str, UNSET) == 0)
		return (1);
	else if (ft_strcmp(str, ENV) == 0)
		return (1);
	else if (ft_strcmp(str, EXIT) == 0)
		return (1);
	return (0);
}

int	ft_is_varenv(char *str)
{
	(void) str;
	return (0);
}

int	ft_is_signal(char *str)
{
	(void) str;
	return (0);
}
