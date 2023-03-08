/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:05:03 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/08 21:05:41 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_token(t_minishell *ms)
{
	int				nb_cmd;
	t_list_token	*pars;
	t_list_cmd		*test;

	(void) nb_cmd;
	pars = ms->token;
	/*nb_cmd = ft_get_nbcmd(pars);
	if (nb_cmd != 1)
		pipe(ms->fd_pipe[nb_cmd - 1][2]);
	*/
	// printf("####################\n");
	// printf("parsing token ->\n");
	while (pars != NULL)
	{
		if (!ms->cmd)
		{
			// printf("FIRST CMD\n");
			ms->cmd = ft_lstnew_cmd(ft_init_cmd(&pars, ms->fd_pipe));
		}
		else
		{
			// printf("OTHER CMD\n");
			ft_lstadd_back_cmd(&ms->cmd, ft_lstnew_cmd(ft_init_cmd(&pars, ms->fd_pipe)));
		}
	}
	test = ms->cmd;
	int	j = 0;
	int	i = 0;
	while (test != NULL)
	{
		// printf(" --- cmd[%d] ---\n", j);
		// printf("[%s] <- cmd\n", test->cmd);
		while (test->option[i] != NULL)
		{
			// printf("[%s] <- option[%d]\n", test->option[i], i);
			i++;
		}
		i = 0;
		// printf("[%d] <- fd_read\n", test->fd_read);
		// printf("[%d] <- fd_write\n", test->fd_write);
		j++;
		test = test->next;
	}
}

int	ft_get_nbcmd(t_list_token *pars)
{
	int	count;

	count = 1;
	while (pars != NULL)
	{
		if (pars->type == E_PIPE)
			count++;
		pars = pars->next;
	}
	return (count);
}
