
#include "minishell.h"

void	ft_execute_external(char **env, struct s_list_cmd *cmd)
{
	char	filepath[256];
	char	**splited_path;
	int		i;

	splited_path = ft_getsplitedpath(env);
	i = 0;
	while (splited_path && splited_path[i] != NULL)
	{

		// or create a filepath variable with malloc?
		strcpy(filepath, splited_path[i]); // TODO repalce with ft version
		strcat(filepath, "/"); // TODO repalce with ft version
		strcat(filepath, cmd->cmd); // TODO repalce with ft version
		if (access(filepath, X_OK) == 0)
		{
			// ft_freesplit(splited_path);  // It is free automaticaly ?
			// ft_free_env(env);
			execve(filepath, cmd->option, env);
		}
		i++;
	}
	if (splited_path)
		ft_freesplit(splited_path);

	ft_putstr_fd("[TODO:Insert command(ft_execute_external.c)] command not found\n", 2);
}
