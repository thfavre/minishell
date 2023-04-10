/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:09:19 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 17:49:01 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe_check(t_list_token *syntax)
{
	if (syntax->type == E_PIPE)
	{
		if (ft_pipe_error(syntax) == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ft_pipe_error(t_list_token *syntax)
{
	t_list_token	*cpy;

	cpy = syntax;
	while (cpy->previous != NULL && cpy->previous->type == E_SPACE)
		cpy = cpy->previous;
	if (cpy->previous != NULL)
	{
		if (cpy->previous->type != E_STRING)
			return (1);
	}
	if (cpy->previous == NULL)
		return (1);
	cpy = syntax;
	while (cpy->next != NULL && cpy->next->type == E_SPACE)
		cpy = cpy->next;
	if (cpy->next != NULL)
	{
		if (cpy->next->type != E_STRING && cpy->next->type != E_REDIRECTION)
			return (1);
	}
	if (cpy->next == NULL)
		return (1);
	return (0);
}
