/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_varenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:16:46 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/08 15:11:04 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int	ft_token_got_varenv(char *str);

void	ft_parse_varenv(t_minishell *ms)
{
	t_list_token	*start;

	start = ms->token;
	while (ms->token != NULL)
	{
		if (ms->token->type == E_STRING && ms->token->quote == E_NONE)
		{
			if (ft_token_got_varenv(ms->token->word) == 1)
				ft_add_varenv_in_token(ms->token, ms->env);
		}
		else if (ms->token->type == E_STRING && ms->token->quote == E_DOUBLE)
		{
			if (ft_token_got_varenv(ms->token->word) == 1)
				ft_replace_varenv(ms->token, ms->env);
		}
	}
	ms->token = start;
}

void	ft_add_varenv_int_token(t_list_token *list, char **env)
{

}

void	ft_replace_varenv(t_list_token *list, char **env)
{

}

int	ft_token_got_varenv(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
