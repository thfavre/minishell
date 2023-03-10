/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/10 18:07:32 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_cd(t_minishell *ms, char **paths)
{
	char	*dest;
	char	old_cwd[1024];
	// TODO check errors of this function

	if (getcwd(old_cwd, sizeof(old_cwd)) == NULL)
		return perror("getcwd() error");
	dest = paths[1];
	if (dest == NULL)
	{
		dest = ft_getenv(ms->env, "HOME");
		if (dest == NULL)
		{
			write(2, "cd: HOME not set\n", 18);
			return ;
		}
	}
	else if (ft_strcmp(dest, "-") == 0)
	{
		dest = ft_getenv(ms->env, "OLDPWD"); // TODO free
		if (dest == NULL)
		{
			write(2, "cd: OLDPWD not set\n", 20);
			return ;
		}
	}
	if (chdir(dest) != 0)
		printf("cd: %s: %s ()\n", paths[1], strerror(errno)); // TODO do in on STDERROR fd...
	else
	{
		ft_setenv(ms, "OLDPWD", old_cwd, 1); // WHY LEAKS?!!!
	}
}
