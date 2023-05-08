/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:02:46 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_destination(t_minishell *ms, char *dest)
{
	if (dest == NULL)
	{
		dest = ft_getenv(ms->env, "HOME");
		if (dest[0] == '\0')
		{
			free(dest);
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (NULL);
		}
	}
	else if (ft_strcmp(dest, "-") == 0)
	{
		dest = ft_getenv(ms->env, "OLDPWD");
		if (dest[0] == '\0')
		{
			free(dest);
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
			return (NULL);
		}
	}
	return (dest);
}

static int	change_directory(t_minishell *ms, char *dest)
{
	char	old_cwd[MAXPATHLEN];

	if (getcwd(old_cwd, sizeof(old_cwd)) == NULL)
	{
		perror("getcwd() error");
		return (errno);
	}
	if (chdir(dest) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(dest, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (errno);
	}
	else
	{
		ft_setenv(ms, "OLDPWD", old_cwd);
		return (EXIT_SUCCESS);
	}
}

int	ft_cd(t_minishell *ms, char **paths)
{
	char	*dest;

	dest = get_destination(ms, paths[1]);
	if (dest == NULL)
		return (EXIT_FAILURE);
	return (change_directory(ms, dest));
}
