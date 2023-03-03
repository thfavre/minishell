/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:05:03 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/03 15:39:51 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_token(t_minishell *ms)
{
	t_list_token	*pars;

	pars = ms->token;
	while (pars != NULL)
	{
		if (!ms->cmd)
		{
			printf("coucou hiboux\n");
			ms->cmd = ft_lstnew_cmd(ft_init_cmd(&pars));
		}
		else
		{
			printf("coucou moi\n");
			ft_lstadd_back_cmd(&ms->cmd, ft_lstnew_cmd(ft_init_cmd(&pars));
		}
	}
}
