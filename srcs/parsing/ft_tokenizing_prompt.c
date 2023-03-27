/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizing_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:51:29 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 12:51:32 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenizing_prompt(t_minishell *ms, char *str)
{
	t_list_token	*token;

	while (ft_isspace(*str) == true)
		str++;
	token = ft_lstnew_token(ft_get_token(&str));
	ms->token = token;
	while (*str != '\0')
		ft_lstadd_back_token(&ms->token, ft_lstnew_token(ft_get_token(&str)));
}

char	*ft_get_token(char **str)
{
	char	*word;

	word = NULL;
	if (**str == '<' || **str == '>' || **str == '|')
		word = ft_getword_redirection(str, (char)**str);
	else if (**str == '\'' || **str == '"')
		word = ft_getword_quote(str, **str);
	else if (**str == ' ')
		word = ft_getword_space(str);
	else if (**str != ' ')
		word = ft_getword(str);
	return (word);
}

int	ft_get_token_type(char *str)
{
	if (ft_is_redirection(str) == 1)
		return (E_REDIRECTION);
	else if (ft_is_pipe(str) == 1)
		return (E_PIPE);
	else if (ft_is_space(str) == 1)
		return (E_SPACE);
	else
		return (E_STRING);
}

int	ft_token_is_quoted(char *str)
{
	if (str[0] == '\'')
		return (E_SINGLE);
	else if (str[0] == '"')
		return (E_DOUBLE);
	return (E_NONE);
}
