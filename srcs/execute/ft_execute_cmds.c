
#include "minishell.h"

void	ft_run_cmd(t_minishell *ms, struct s_list_cmd *cmd);

void	ft_execute_cmds(t_minishell *ms)
{
	struct s_list_cmd *cmd = ms->cmd;
	int fd_pipe_read_tmp = 0;
	int fd_pipe[2];
	// if only one command => No need of a fork for ONLY the builtins ^^

	while (cmd)
	{
		pipe(fd_pipe);
		pid_t fork_pid = fork();
		if (fork_pid == 0) // child
		{
			// read
			if (cmd->fd_read > 3)
				close(fd_pipe[0]);
			else
				cmd->fd_read = fd_pipe_read_tmp;
			dup2(cmd->fd_read, 0);

			// write
			if (cmd->fd_write > 3)
				close(fd_pipe[1]);
			else if (!cmd->next)
				cmd->fd_write = 1;
			else
				cmd->fd_write = fd_pipe[1];
			dup2(cmd->fd_write, 1); // write

			ft_run_cmd(ms, cmd);
			// execvp(cmd->cmd, cmd->option);
		}
		// parent
		close(fd_pipe[1]);
		fd_pipe_read_tmp = fd_pipe[0];

		cmd = cmd->next;
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	// while (waitpid(-1, NULL, WUNTRACED) == -1)
	// 	;
	// wait for all child processes to finish
	while (waitpid(-1, NULL, 0) > 0)
		;
}

void	ft_run_cmd(t_minishell *ms, struct s_list_cmd *cmd)
{
	if (ft_is_builtins(cmd->cmd))
		ft_execute_builtin(ms, cmd);
	else
		ft_execute_external(ms->env, cmd);
	exit(0);
}
