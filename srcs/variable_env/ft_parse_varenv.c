/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_varenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:16:46 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/08 16:45:00 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int		ft_token_got_varenv(char *str);
char	*ft_get_name_varenv(char *str);

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

void	ft_add_varenv_in_token(t_list_token *token, char **env)
{
}

void	ft_replace_varenv(t_list_token *list, char **env)
{
	size_t	i;
	char	*var_env;

	i = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
		{
			var_env = ft_get_name_varenv(&token->word[i]);

		}
		i++;
	}
}

char	*ft_get_name_varenv(char *str)
{
	char	*var_env;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == '$' || str[i] == ' ')
			break ;
		len++;
		i++;
	}
	var_env = ft_calloc(sizeof(char), len + 1);
	if (!var_env)
		return (NULL);
	i = 0;
	while (i < len)
	{
		var_env[i] = str[i];
		i++;
	}	
	return (var_env);
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
