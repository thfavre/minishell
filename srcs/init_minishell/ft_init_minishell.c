
#include "minishell.h"

void	ft_init_minishell(t_minishell *ms, char **env)
{
	*ms = (t_minishell) {};
	ms->env = ft_initenv(env);
	// ms->last_exit_status = EXIT_SUCCESS; //TODO correct?
}
