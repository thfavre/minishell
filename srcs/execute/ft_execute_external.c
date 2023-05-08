/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_external.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:40:21 by thomas            #+#    #+#             */
/*   Updated: 2023/04/12 18:21:20 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_external(char **env, struct s_list_cmd *cmd)
{
	char	filepath[MAXPATHLEN];
	char	**splited_path;
	int		i;

	if (access(cmd->cmd, X_OK) == 0)
		execve(cmd->cmd, cmd->option, env);
	splited_path = ft_getsplitedpath(env);
	i = 0;
	while (splited_path && splited_path[i] != NULL)
	{
		ft_strcpy(filepath, splited_path[i]);
		ft_strcat(filepath, "/");
		ft_strcat(filepath, cmd->cmd);
		if (access(filepath, X_OK) == 0)
		{
			execve(filepath, cmd->option, env);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (splited_path)
		ft_freesplit(splited_path);
	ft_putstr_fd(cmd->cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}
