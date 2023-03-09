
#include "minishell.h"

void ft_exit(t_minishell *ms)
{
	ft_free_env(ms->env);
	// ft_free_path(ms); // TODO change ms to ms->path to be more specific (or remove this and replace with ft_getenv("PATH") when implemented)
	printf("exit\n");
}
