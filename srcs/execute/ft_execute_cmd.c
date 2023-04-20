/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:26:33 by thomas            #+#    #+#             */
/*   Updated: 2023/04/20 13:37:49 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execute_external_in_fork(t_minishell *ms, pid_t *fork_pid,
			int *exit_status)
{
	*fork_pid = fork();
	if (*fork_pid == 0)
		ft_execute_external(ms->env, ms->cmd);
	waitpid(*fork_pid, exit_status, 0);
	if (WIFEXITED(*exit_status))
		g_last_exit_status = WEXITSTATUS(*exit_status);
	else if (WIFSIGNALED(*exit_status))
		g_last_exit_status = 128 + WTERMSIG(*exit_status);
	else
		g_last_exit_status = 1;
}

void	ft_execute_cmd(t_minishell *ms)
{
	pid_t	fork_pid;
	int		exit_status;
	int		original_stdin;
	int		original_stdout;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	if (ms->cmd->fd_read >= 3)
		dup2(ms->cmd->fd_read, STDIN_FILENO);
	if (ms->cmd->fd_write >= 3)
		dup2(ms->cmd->fd_write, STDOUT_FILENO);
	if (ft_is_builtins(ms->cmd->cmd))
		g_last_exit_status = ft_execute_builtin(ms, ms->cmd);
	else
		ft_execute_external_in_fork(ms, &fork_pid, &exit_status);
	if (ms->cmd->fd_read >= 3)
		close(ms->cmd->fd_read);
	if (ms->cmd->fd_write >= 3)
		close(ms->cmd->fd_write);
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	close(original_stdin);
}
