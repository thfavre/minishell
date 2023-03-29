/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:36:40 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/28 14:52:02 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirection_error(t_list_token *syntax);

int	ft_redirection_check(t_list_token *syntax)
{
	if (syntax->type == E_REDIRECTION && syntax->next != NULL)
	{
		if (ft_redirection_error(syntax) == 1)
			return (1);
	}
	if (syntax->type == E_REDIRECTION && syntax->next == NULL)
		return (1);
	return (0);
}

int	ft_redirection_error(t_list_token *syntax)
{
	t_list_token	*cpy;

	cpy = syntax;
	while (cpy->next->type == E_SPACE)
	{
		cpy = cpy->next;
		if (cpy->next == NULL)
			return (1);
	}
	if (cpy->next->type != E_STRING)
		return (1);
	return (0);
}
