

#include "minishell.h"


int	ft_unsetenv(char **env, char *key) // it does just slide up all values after the key
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (key == NULL || key[0] == '\0' || strchr(key, '=') != NULL) // TODO repalce with ft version
		return (-1);
	len = ft_strlen(key);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')	// it is the line to remove! ^^
		{
			j = i;
			while (env[j] != NULL)
			{
				env[j] = env[j + 1];
				j++;
			}
			free(env[j]); // Is it leak free?
		}
		i++;
	}
	return (0);
}

/* Remove a the key and value of a key.
Ex : ft_removeenv(env, "pouic=ls")*/
// char	**ft_removeenv(char **env, char *key)
// {
// 	int		env_size;
// 	char	**new_env;
// 	size_t	key_end_index;


// 	env_size = 0;
// 	while (env[env_size++])
// 		;
// 	new_env = ft_calloc(sizeof(*new_env), (env_size + 1));
// 	if (!new_env)
// 		return (NULL);
// 	env_size = -1;
// 	while (env[++env_size] != NULL)
// 	{
// 		key_end_index = 0;
// 		while (env[env_size][key_end_index] != '=')
// 			key_end_index++;
// 		if (ft_strncmp(env[env_size], key, key_end_index) != 0)
// 			continue;
// 		new_env[env_size] = ft_calloc(sizeof(**new_env), strlen(env[env_size]) + 1);
// 		if (!new_env[env_size])
// 			return (ft_free_env(new_env));
// 		new_env[env_size] = strdup(env[env_size]); // TODO repalce with ft version
// 	}
// 	return (new_env);
// }
