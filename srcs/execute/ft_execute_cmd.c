
#include "minishell.h"

void	ft_execute_cmd(t_minishell *ms)
{
	pid_t	fork_pid;
	int		exit_status;
	int original_stdin;
	int original_stdout;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	if (ms->cmd->fd_read > 3)
		dup2(ms->cmd->fd_read, STDIN_FILENO);
	if (ms->cmd->fd_write > 3)
		dup2(ms->cmd->fd_write, STDOUT_FILENO);
	if (ft_is_builtins(ms->cmd->cmd))
		last_exit_status = ft_execute_builtin(ms, ms->cmd);
	else
	{
		fork_pid = fork();
		if (fork_pid == 0)
			ft_execute_external(ms->env, ms->cmd);
		waitpid(fork_pid, &exit_status, 0);
		last_exit_status = WEXITSTATUS(exit_status);
	}
	if (ms->cmd->fd_read > 3)
		close(ms->cmd->fd_read);
	if (ms->cmd->fd_write > 3)
		close(ms->cmd->fd_write);
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
}

