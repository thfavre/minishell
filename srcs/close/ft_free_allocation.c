/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_allocation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:50:42 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:51:17 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		free(env[i++]);
	free(env);
	return (NULL);
}

void	ft_free_token(t_minishell *ms)
{
	t_list_token	*tmp;

	ft_del_heredoc(ms->token);
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

	while (ms->cmd != NULL)
	{
		tmp = ms->cmd;
		ms->cmd = ms->cmd->next;
		free(tmp->option);
		free(tmp);
	}
}
