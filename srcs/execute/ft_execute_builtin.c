/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:37:59 by thomas            #+#    #+#             */
/*   Updated: 2023/03/08 20:38:13 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_builtin(t_minishell *ms, struct s_list_cmd *cmd)
{
	if (ft_strcmp("pwd", cmd->cmd) == 0)
		ft_pwd();
	else if (ft_strcmp("env", cmd->cmd) == 0)
		ft_env(ms->env);
	else if (ft_strcmp("cd", cmd->cmd) == 0)
		ft_cd(cmd->option);
}
