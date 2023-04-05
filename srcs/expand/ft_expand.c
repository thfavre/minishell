/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:26:05 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/05 15:57:44 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expand(t_minishell *ms)
{
	t_list_token	*start;
	int				code_error;

	code_error = 0;
	start = ms->token;
	while (ms->token != NULL)
	{
		ft_skip_dollars_alone(ms);
		if (ms->token == NULL)
			break ;
		if (ms->token->type == E_STRING && ms->token->quote == E_NONE)
		{
			if (ft_token_got_varenv(ms->token->word) == 1)
				code_error = ft_add_varenv_in_token(ms->token, ms->env);
		}
		else if (ms->token->type == E_STRING && ms->token->quote == E_DOUBLE)
		{
			if (ft_token_got_varenv(ms->token->word) == 1)
				code_error = ft_replace_varenv(ms->token, ms->env, 0);
		}
		ms->token = ms->token->next;
	}
	ms->token = start;
	return (code_error);
}

void	ft_skip_dollars_alone(t_minishell *ms)
{
	while (ms->token != NULL)
	{
		if (ft_dollars_alone(ms->token->word) == 0)
			break ;
		ms->token = ms->token->next;
	}
}

int	ft_dollars_alone(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] == '\0')
			return (1);
		else if (str[i] == '$' && str[i + 1] == '"')
			return (1);
		i++;
	}
	return (0);
}
