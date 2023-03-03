/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizing_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:03:11 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/03 11:27:27 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenizing_prompt(t_minishell *ms, char *str)
{
	t_list	*token;

	while (*str == ' ' && *str == '\t')
		str++;
	token = ft_lstnew_token(ft_get_token(&str));
	ms->token = token;
	while (*str != '\0')
		ft_lstadd_back(&ms->token, ft_lstnew_token(ft_get_token(&str)));
}

char	*ft_get_token(char **str)
{
	char	*word;

	word = NULL;
	if (**str == '\'' || **str == '"')
		word = ft_getword_quote(str, (char)**str);
	else if (**str == '<' || **str == '>' || **str == '|')
		word = ft_getword_redirection(str, (char)**str);
	else if (**str == ' ')
		word = ft_getword_space(str);
	else if (**str != ' ')
		word = ft_getword(str);
	return (word);
}
