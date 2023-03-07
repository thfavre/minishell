
#include "minishell.h"


char	**ft_putenv(char **env, char *string);

int	ft_setenv(t_minishell *ms, char *key, char *value, int overwrite)
{
	char	*new_element;
	char	**new_env;

	if (key == NULL || key[0] == '\0' || strchr(key, '=') != NULL ||
			value == NULL)
		return -1;
	if (ft_getenv(ms->env, key) != NULL)
	{
		if (overwrite == 0)
			return 0;
		ft_unsetenv(ms->env, key);
	}
	new_element = malloc(strlen(key) + strlen(value) + 2);
								/* +2 for '=' and null terminator */
	if (new_element == NULL)
		return -1;
	strcpy(new_element, key); // TODO repalce with ft version
	strcat(new_element, "="); // TODO repalce with ft version
	strcat(new_element, value); // TODO repalce with ft version
	new_env = ft_putenv(ms->env, new_element);
	ft_free_env(ms->env);
	ms->env = new_env;
	if (new_env != NULL)
		return (0);
	return (1);
}

/* Add a string to the env.
Ex : ft_putenv(env, "pouic=ls")*/
char	**ft_putenv(char **env, char *string)
{
	int		env_size;
	char	**new_env;

	env_size = 0;
	while (env[env_size++])
		;
	new_env = ft_calloc(sizeof(*new_env), (env_size + 2));
	if (!new_env)
		return (NULL);
	env_size = -1;
	while (env[++env_size] != NULL)
	{
		new_env[env_size] = ft_calloc(sizeof(**new_env), strlen(env[env_size]) + 1);
		if (!new_env[env_size])
			return (ft_free_env(new_env));
		new_env[env_size] = strdup(env[env_size]); // TODO repalce with ft version
	}
	new_env[env_size] = ft_calloc(sizeof(**new_env), strlen(string) + 1);
	if (!new_env[env_size])
			return (ft_free_env(new_env));
	new_env[env_size] = strdup(string); // TODO repalce with ft version
	return (new_env);
}

// void	*ft_free_env(char **env)
// {
// 	int	i;

// 	i = 0;
// 	while (env[i])
// 		free(env[i++]);
// 	free(env);
// 	return (NULL);
// }
