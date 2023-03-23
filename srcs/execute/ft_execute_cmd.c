
#include "minishell.h"

void	ft_execute_cmd(t_minishell *ms)
{
	pid_t fork_pid;
	printf("--->%s\n", ms->cmd->cmd);

	if (ft_is_builtins(ms->cmd->cmd))
	{
		ft_execute_builtin(ms, ms->cmd);
		return ;
	}
	fork_pid = fork();
	if (fork_pid == 0)
	{
		ft_execute_external(ms->env, ms->cmd);
		exit(0); // NEEDED TO EXIT CHILD PROCESS

	}
	waitpid(fork_pid, NULL, 0);
}


