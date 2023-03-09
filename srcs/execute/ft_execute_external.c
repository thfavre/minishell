/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_external.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:38:55 by thomas            #+#    #+#             */
/*   Updated: 2023/03/08 22:24:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_external(char **env, struct s_list_cmd *cmd)
{
	char	filepath[256];
	char	**splited_path;
	int		i;

	splited_path = ft_getsplitedpath(env);
	i = 0;
	while (splited_path[i] != NULL)
	{

		// or create a filepath variable with malloc?
		strcpy(filepath, splited_path[i]); // TODO repalce with ft version
		strcat(filepath, "/"); // TODO repalce with ft version
		strcat(filepath, cmd->cmd); // TODO repalce with ft version
		if (access(filepath, X_OK) == 0)
		{
			ft_freesplit(splited_path);
			execve(filepath, cmd->option, env);
		}
		i++;
	}
	ft_freesplit(splited_path);
	write(2, "[TODO:Insert command(ft_execute_external.c)] command not found\n", 64); // TODO replace with a function?
}
