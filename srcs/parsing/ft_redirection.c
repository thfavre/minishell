/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:53:01 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 12:53:40 by mjulliat         ###   ########.fr       */
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
		fd = open((*pars)->word, O_TRUNC | O_CREAT | O_RDWR, 0644);
	return (fd);
}
