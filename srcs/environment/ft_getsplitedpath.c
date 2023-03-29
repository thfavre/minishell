
#include "minishell.h"

char	**ft_getsplitedpath(char **env)
{
	char	*unsplited_path;
	char	**splited_path;

	// if (!env[0])
	// 	return (NULL);
	unsplited_path = ft_getenv(env, "PATH");
	if (unsplited_path == NULL || unsplited_path[0] == '\0')
		return (NULL);
	splited_path = ft_split(unsplited_path + 5, ':');
	// free(unsplited_path);
	return (splited_path);
}
