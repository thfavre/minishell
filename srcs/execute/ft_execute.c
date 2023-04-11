/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:40:40 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 15:41:02 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(t_minishell *ms)
{
	if (ms->cmd->cmd != NULL)
	{
		if (ms->cmd->next == NULL)
			ft_execute_cmd(ms);
		else
			ft_execute_cmds(ms);
	}
}
