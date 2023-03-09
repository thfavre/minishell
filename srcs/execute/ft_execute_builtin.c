
#include "minishell.h"

void	ft_execute_builtin(t_minishell *ms, struct s_list_cmd *cmd)
{
	if (ft_strcmp("pwd", cmd->cmd) == 0)
		ft_pwd();
	else if (ft_strcmp("env", cmd->cmd) == 0)
		ft_env(ms->env);
	else if (ft_strcmp("cd", cmd->cmd) == 0)
		ft_cd(ms, cmd->option);
}
