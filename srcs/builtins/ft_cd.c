/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/27 16:34:06 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_minishell *ms, char **paths)
{
	char	*dest;
	char	old_cwd[1024];
	// TODO check errors of this function

	if (getcwd(old_cwd, sizeof(old_cwd)) == NULL)
	{
		perror("getcwd() error");
		return (errno);
	}
	dest = paths[1];
	if (dest == NULL)
	{
		dest = ft_getenv(ms->env, "HOME");
		if (dest == NULL)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (EXIT_FAILURE);
		}
	}
	else if (ft_strcmp(dest, "-") == 0)
	{
		dest = ft_getenv(ms->env, "OLDPWD"); // TODO free
		if (dest == NULL)
		{
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
			return (EXIT_FAILURE);

		}
	}
	if (chdir(dest) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(dest, 2);
		ft_putstr_fd(": No such file or directory\n", 2); // should write (strerror(errno) but it takes too much lines...)
		return (errno);
	}
	else
		ft_setenv(ms, "OLDPWD", old_cwd, 1); // WHY LEAKS?!!!
	return (EXIT_SUCCESS);
}
