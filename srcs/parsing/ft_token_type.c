/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:51:35 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/29 16:10:25 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// (Do not erase, I need this function for the execution)
int	ft_is_builtins(char *str)
{
	if (ft_strcmp(str, D_ECHO) == 0)
		return (1);
	else if (ft_strcmp(str, D_CD) == 0)
		return (1);
	else if (ft_strcmp(str, D_PWD) == 0)
		return (1);
	else if (ft_strcmp(str, D_EXPORT) == 0)
		return (1);
	else if (ft_strcmp(str, D_UNSET) == 0)
		return (1);
	else if (ft_strcmp(str, D_ENV) == 0)
		return (1);
	else if (ft_strcmp(str, D_EXIT) == 0)
		return (1);
	return (0);
}

int	ft_is_redirection(char *str)
{
	if (ft_strcmp(str, D_INFILE) == 0)
		return (1);
	else if (ft_strcmp(str, D_OUTFILE) == 0)
		return (1);
	else if (ft_strcmp(str, D_HEREDOC) == 0)
		return (1);
	else if (ft_strcmp(str, D_APPEND) == 0)
		return (1);
	return (0);
}

int	ft_which_redirection(char *str)
{
	if (ft_strcmp(str, D_INFILE) == 0)
		return (E_INFILE);
	else if (ft_strcmp(str, D_OUTFILE) == 0)
		return (E_OUTFILE);
	else if (ft_strcmp(str, D_HEREDOC) == 0)
		return (E_HEREDOC);
	else if (ft_strcmp(str, D_APPEND) == 0)
		return (E_APPEND);
	return (E_NORED);

}

int	ft_is_pipe(char *str)
{
	if (ft_strcmp(str, D_PIPE) == 0)
		return (1);
	return (0);
}

int	ft_is_space(char *str)
{
	if (*str == ' ' || *str == '\t')
		return (1);
	return (0);
}
