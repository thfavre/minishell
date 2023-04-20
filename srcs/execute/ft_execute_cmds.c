/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:36:17 by thomas            #+#    #+#             */
/*   Updated: 2023/04/20 13:33:15 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prepare_fds(struct s_list_cmd *cmd, int *fd_pipe_read_tmp,
				int *fd_pipe)
{
	close(fd_pipe[0]);
	if (cmd->fd_read == 0)
		cmd->fd_read = *fd_pipe_read_tmp;
	dup2(cmd->fd_read, 0);
	if (cmd->fd_write >= 3)
		close(fd_pipe[1]);
	else if (!cmd->next)
		cmd->fd_write = 1;
	else
		cmd->fd_write = fd_pipe[1];
	dup2(cmd->fd_write, 1);
}

static void	close_fds(struct s_list_cmd *cmd, int *fd_pipe_read_tmp,
				int *fd_pipe)
{
	close(fd_pipe[1]);
	if (*fd_pipe_read_tmp >= 3)
		close(*fd_pipe_read_tmp);
	if (cmd->fd_write >= 3)
		close(cmd->fd_write);
	if (cmd->fd_read >= 3)
		close(cmd->fd_read);
	*fd_pipe_read_tmp = fd_pipe[0];
}

static void	ft_run_cmd(t_minishell *ms, struct s_list_cmd *cmd)
{
	if (!ft_is_builtins(cmd->cmd))
		ft_execute_external(ms->env, cmd);
	exit(ft_execute_builtin(ms, cmd));
}

static void	handle_exit_status(int exit_status)
{
	if (WIFEXITED(exit_status))
		g_last_exit_status = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		g_last_exit_status = 128 + WTERMSIG(exit_status);
	else
		g_last_exit_status = 1;
}

void	ft_execute_cmds(t_minishell *ms)
{
	struct s_list_cmd	*cmd;
	int					fd_pipe_read_tmp;
	int					fd_pipe[2];
	int					exit_status;
	pid_t				fork_pid;

	cmd = ms->cmd;
	fd_pipe_read_tmp = 0;
	while (cmd)
	{
		pipe(fd_pipe);
		fork_pid = fork();
		if (fork_pid == 0)
		{
			prepare_fds(cmd, &fd_pipe_read_tmp, fd_pipe);
			ft_run_cmd(ms, cmd);
		}
		close_fds(cmd, &fd_pipe_read_tmp, fd_pipe);
		cmd = cmd->next;
	}
	while (waitpid(-1, &exit_status, 0) > 0)
		;
	handle_exit_status(exit_status);
}
