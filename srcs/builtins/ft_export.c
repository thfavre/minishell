/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:37:48 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_key_value(t_minishell *ms, char *option, int *exit_status);
static void	export_key(t_minishell *ms, char *option, int *exit_status);
void		ft_print_export(char **env);
static bool	is_valid_key(char *key);

int	ft_export(t_minishell *ms, char **option)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	option++;
	if (*option == NULL)
		ft_print_export(ms->env);
	while (*option)
	{
		if (strchr(*option, '=') != NULL)
			export_key_value(ms, *option, &exit_status);
		else
			export_key(ms, *option, &exit_status);
		option++;
	}
	return (exit_status);
}

static void	export_key_value(t_minishell *ms, char *option, int *exit_status)
{
	char	*key;
	char	*value;

	key = ft_strdup(option);
	if (!key)
		return ;
	key[ft_strlen(option) - ft_strlen(ft_strchr(option, '='))] = '\0';
	value = ft_strchr(option, '=') + 1;
	if (is_valid_key(key))
		ft_setenv(ms, key, value);
	else
		*exit_status = EXIT_FAILURE;
	free(key);
}

static void	export_key(t_minishell *ms, char *option, int *exit_status)
{
	if (is_valid_key(option))
		ft_setenv(ms, option, "");
	else
		*exit_status = EXIT_FAILURE;
}

static bool	is_valid_key(char *key)
{
	if (ft_strlen(key) == 0 || !ft_isalpha(key[0]) || !ft_str_isalnum(key))
	{
		ft_putstr_fd("export: '", STDERR_FILENO);
		ft_putstr_fd(key, STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		return (false);
	}
	return (true);
}
