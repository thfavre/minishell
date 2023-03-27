
#include "minishell.h"

void ft_close(t_minishell *ms)
{
	ft_putstr_fd("exit\n", 1); // TODO in on STDERROR or STDOUT fd ?
	ft_free_env(ms->env);
	rl_clear_history();
	// ft_free_path(ms); // TODO change ms to ms->path to be more specific (or remove this and replace with ft_getenv("PATH") when implemented)
	// printf("??exit??\n"); // message done in ft_exit.c
}
