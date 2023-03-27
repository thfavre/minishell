
#include "minishell.h"

int	ft_execute_builtin(t_minishell *ms, struct s_list_cmd *cmd)
{
	int	exit_status;

	exit_status = 13;
	if (ft_strcmp("pwd", cmd->cmd) == 0)
		exit_status = ft_pwd();
	else if (ft_strcmp("env", cmd->cmd) == 0)
		exit_status = ft_env(ms->env);
	else if (ft_strcmp("cd", cmd->cmd) == 0)
		exit_status = ft_cd(ms, cmd->option);
	else if (ft_strcmp("echo", cmd->cmd) == 0)
		exit_status = ft_echo(cmd->option);
	else if (ft_strcmp("export", cmd->cmd) == 0)
		exit_status = ft_export(ms, cmd->option);
	else if (ft_strcmp("unset", cmd->cmd) == 0)
		exit_status = ft_unset(ms->env, cmd->option);
	else if (ft_strcmp("exit", cmd->cmd) == 0)
		ft_exit(ms, cmd->option);
	return (exit_status);
}
