/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:42:45 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/03 14:43:28 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_is_var_env(char *str)
{
	if (*str == '$')
		return (1);
	return (0);
}
