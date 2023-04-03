/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:28:16 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/30 11:23:37 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_list_cmd(t_list_cmd *cmd)
{
	t_list_cmd	*test;
	int			i;
	int			j;

	i = 0;
	j = 1;
	test = cmd;
	printf("PARSING TOKEN -> \n");
	while (test != NULL)
	{
		printf(" --- cmd[%d] ---\n", j++);
		printf("[%s] <- cmd\n", test->cmd);
		if (test->cmd != NULL)
		{
			while (test->option[i] != NULL)
			{
				printf("[%s] <- option[%d]\n", test->option[i], i);
				i++;
			}
		}
		i = 0;
		printf("[%d] <- fd_read\n", test->fd_read);
		printf("[%d] <- fd_write\n", test->fd_write);
		test = test->next;
	}
}

void	ft_parse_token(t_minishell *ms)
{
	t_list_token	*pars;
	t_list_token	*start;

	start = ms->token;
	pars = ms->token;
	while (pars != NULL)
	{
		if (!ms->cmd)
			ms->cmd = ft_lstnew_cmd(ft_init_cmd(&pars));
		else
			ft_lstadd_back_cmd(&ms->cmd, ft_lstnew_cmd(ft_init_cmd(&pars)));
	}
	ms->token = start;
	if (DEBUG == 1)
		ft_print_list_cmd(ms->cmd);
}
