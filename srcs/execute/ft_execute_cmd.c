
#include "minishell.h"

void	ft_execute_cmd(t_minishell *ms)
{
	pid_t	fork_pid;
	int		exit_status;
	int original_stdin;
	int original_stdout;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);

	if (ms->cmd->fd_read > 2 || ms->cmd->fd_read == 0)
		dup2(ms->cmd->fd_read, 0); //STDIN_FILENO
	if (ms->cmd->fd_write > 2 ||  ms->cmd->fd_write == 1)
		dup2(ms->cmd->fd_write, 1); //STDOUT_FILENO
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
	if (ms->cmd->fd_read > 2)

		close(ms->cmd->fd_read);

	if (ms->cmd->fd_write > 2)
		close(ms->cmd->fd_write);
	// printf("\n\nTEST1\n\n");
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
}

