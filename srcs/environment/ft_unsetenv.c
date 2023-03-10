

#include "minishell.h"


int	ft_unsetenv(char **env, char *key)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (key == NULL || key[0] == '\0' || ft_strchr(key, '=') != NULL)
		return (-1);
	len = ft_strlen(key);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
		{
			j = i;
			while (env[j] != NULL)
			{
				if (env[j] != NULL)
					free(env[j]);
				if (env[j + 1] != NULL)
					env[j] = ft_strdup(env[j + 1]);
				else
					env[j] = NULL;
				j++;
			}
			// free(env[j]); // Is it leak free?
		}
		i++;
	}
	return (0);
}
