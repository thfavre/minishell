
#include "minishell.h"

void	ft_execute_cmd(t_minishell *ms)
{
	pid_t	fork_pid;
	int		exit_status;

	if (ft_is_builtins(ms->cmd->cmd))
	{
		last_exit_status = ft_execute_builtin(ms, ms->cmd);
		// ms->last_exit_status = ft_execute_builtin(ms, ms->cmd);
		return ;
	}
	fork_pid = fork();
	if (fork_pid == 0)
		ft_execute_external(ms->env, ms->cmd);
	waitpid(fork_pid, &exit_status, 0);
	// ms->last_exit_status = WEXITSTATUS(exit_status);
	last_exit_status = WEXITSTATUS(exit_status);
}


