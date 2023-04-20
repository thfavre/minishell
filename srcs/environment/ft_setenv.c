/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:08:03 by thomas            #+#    #+#             */
/*   Updated: 2023/04/12 13:11:38 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_setenv(t_minishell *ms, char *key, char *value)
{
	char	*new_element;
	char	**new_env;

	if (key == NULL || key[0] == '\0' || ft_strchr(key, '=') != NULL || \
			value == NULL)
		return (-1);
	ft_unsetenv(ms->env, key);
	new_element = malloc(ft_strlen(key) + ft_strlen(value) + 2);
	if (new_element == NULL)
		return (-1);
	ft_strcpy(new_element, key);
	if (value[0] != '\0')
		ft_strcat(new_element, "=");
	ft_strcat(new_element, value);
	new_env = ft_putenv(ms->env, new_element);
	ft_free_env(ms->env);
	ms->env = new_env;
	free(new_element);
	return (new_env != NULL);
}

/* Add a string to the env.
Ex : ft_putenv(env, "pouic=ls")*/
char	**ft_putenv(char **env, char *string)
{
	int		env_size;
	char	**new_env;
	int		i;

	env_size = 0;
	while (env[env_size++])
		;
	new_env = ft_calloc(env_size + 2, sizeof(*new_env));
	if (!new_env)
		return (NULL);
	i = 0;
	while (env[i] != NULL)
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
			return (ft_free_env(new_env));
		i++;
	}
	new_env[i] = ft_strdup(string);
	if (!new_env[i])
		return (ft_free_env(new_env));
	return (new_env);
}
