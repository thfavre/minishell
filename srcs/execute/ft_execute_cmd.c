/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:40:30 by thomas            #+#    #+#             */
/*   Updated: 2023/03/09 00:24:06 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_cmd(t_minishell *ms)
{
	pid_t fork_pid;

	if (ft_is_builtins(ms->cmd->cmd))
	{
		ft_execute_builtin(ms, ms->cmd);
		return ;
	}
	fork_pid = fork();
	if (fork_pid == 0)
	{
		ft_execute_external(ms->env, ms->cmd);
		exit(0);
	}
	waitpid(fork_pid, NULL, 0);
}


