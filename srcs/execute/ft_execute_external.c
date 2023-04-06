
#include "minishell.h"

// void sigint_handler(int sig) {
// 	ft_putstr_fd("ERRRRR\n", 2);
// }
void test_handler(int sig)
{
	printf("TEST SIGNAL %d\n", sig);
	exit(1);
}

void	ft_execute_external(char **env, struct s_list_cmd *cmd)
{
	char	filepath[MAXPATHLEN];
	char	**splited_path;
	int		i;
	// signal(SIGINT, sigint_handler);
	// ft_putstr_fd("2\n", 2);
	signal(SIGINT, test_handler);
	signal(SIGQUIT, test_handler);

	if (access(cmd->cmd, X_OK) == 0)
		execve(cmd->cmd, cmd->option, env);
	splited_path = ft_getsplitedpath(env);
	i = 0;
	while (splited_path && splited_path[i] != NULL)
	{
		strcpy(filepath, splited_path[i]); // TODO repalce with ftcat  version
		strcat(filepath, "/"); // TODO repalce with ft version
		strcat(filepath, cmd->cmd); // TODO repalce with ft version
		if (access(filepath, X_OK) == 0)
		{
			// ft_freesplit(splited_path);  // It is free automaticaly ?
			// ft_free_env(env);
			execve(filepath, cmd->option, env);
			// ft_putstr_fd("AAA\n", 2);
			exit(EXIT_FAILURE); // if execve had a problem
		}
		i++;
	}
	if (splited_path)
		ft_freesplit(splited_path);
	ft_putstr_fd(cmd->cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}
