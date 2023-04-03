/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:53:01 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/03 18:08:20 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_infile(t_list_token **pars)
{
	int	fd;

	fd = 0;
	(*pars) = (*pars)->next;
	if ((*pars) == NULL)
		return (fd);
	while ((*pars)->type == E_SPACE)
	{
		if ((*pars)->next == NULL)
		{
			(*pars) = (*pars)->next;
			break ;
		}
		(*pars) = (*pars)->next;
	}
	if ((*pars) != NULL)
		fd = open((*pars)->word, O_RDONLY);
	if (fd == -1)
		last_exit_status = ft_open_failed((*pars)->word);
	else
		last_exit_status = 0;
	return (fd);
}

int	ft_get_outfile(t_list_token **pars)
{
	int	fd;

	fd = 1;
	(*pars) = (*pars)->next;
	if ((*pars) == NULL)
		return (fd);
	while ((*pars)->type == E_SPACE)
	{
		if ((*pars)->next == NULL)
		{
			(*pars) = (*pars)->next;
			break ;
		}
		(*pars) = (*pars)->next;
	}
	if ((*pars) != NULL)
		fd = open((*pars)->word, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	last_exit_status = 0;
	return (fd);
}

int	ft_get_outfile_append(t_list_token **pars)
{
	int	fd;

	fd = 1;
	(*pars) = (*pars)->next;
	if ((*pars) == NULL)
		return (fd);
	while ((*pars)->type == E_SPACE)
	{
		if ((*pars)->next == NULL)
		{
			(*pars) = (*pars)->next;
			break ;
		}
		(*pars) = (*pars)->next;
	}
	if ((*pars) != NULL)
		fd = open((*pars)->word, O_APPEND | O_CREAT | O_WRONLY, 0644);
	last_exit_status = 0;
	return (fd);
}

int	ft_open_failed(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	return (1);
}
