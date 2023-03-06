/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_allocation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:58:36 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/06 16:38:10 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_env(t_minishell *ms)
{
	int	i;

	i = 0;
	while (ms->env[i] != NULL)
	{
		free(ms->env[i]);
		i++;
	}
	free(ms->env);
}

void	ft_free_path(t_minishell *ms)
{
	int	i;

	i = 0;
	while (ms->path[i] != NULL)
	{
		free(ms->path[i]);
		i++;
	}
	free(ms->path);
}

void	ft_free_token(t_minishell *ms)
{
	t_list_token	*tmp;

	while (ms->token != NULL)
	{
		tmp = ms->token;
		ms->token = ms->token->next;
		free(tmp->word);
		free(tmp);
	}
}

void	ft_free_pars(t_minishell *ms)
{
	t_list_cmd	*tmp;
	int			i;

	i = 0;
	while (ms->cmd != NULL)
	{
		tmp = ms->cmd;
		ms->cmd = ms->cmd->next;
		free(tmp->option);
		free(tmp);
	}
}
