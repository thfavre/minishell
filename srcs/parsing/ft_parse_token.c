/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:05:03 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 15:39:10 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_token(t_minishell *ms)
{
	t_list	*pars;

	pars = ms->token;
	ft_check_redirection(ms, pars);
}

void	ft_check_redirection(t_minishell *ms, t_list *pars)
{
	int	type;

	while (pars != NULL)
	{
		type = ft_is_redirection(pars->word);
		if (type == 0)
			pars = pars->next;
		else
		{
			if (type == INFILE)
			{
				ms->fd_infile = ft_get_infile(pars);
				break ;
			}
			else if (type == OUTFILE)
			{
				ms->fd_outfile = ft_get_outfile(pars);
				break ;
			}
		}
	}
}
