/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:26:05 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/11 13:47:22 by mjulliat         ###   ########.fr       */
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
				code_error = ft_add_varenv_in_token(ms->token, ms->env, 0);
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

int	ft_norm_expand(t_list_token *token, char ***venv, char **env, size_t i)
{
	int		save;
	size_t	nb_venv;
	char	*name_venv;

	save = -1;
	nb_venv = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
		{
			name_venv = ft_get_name_varenv(&token->word[++i]);
			if (*name_venv == '?')
				save = nb_venv;
			(*venv)[nb_venv++] = ft_getenv(env, name_venv);
			free(name_venv);
		}
		else
			i++;
	}
	return (save);
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

void	ft_free_empty_venv(char **venv)
{
	size_t	i;

	i = 0;
	while (venv[i] != NULL)
	{
		if (venv[i][0] == '\0')
			free(venv[i]);
		i++;
	}
}
