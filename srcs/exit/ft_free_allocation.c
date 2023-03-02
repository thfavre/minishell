/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_allocation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:58:36 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 14:09:08 by thfavre          ###   ########.fr       */
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
	t_list	*tmp;

	tmp = ms->token;
	while (ms->token != NULL)
	{
		tmp = ms->token;
		ms->token = ms->token->next;
		free(tmp->word);
		free(tmp);
	}
}
