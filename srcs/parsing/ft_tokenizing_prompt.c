/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizing_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:03:11 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 10:25:17 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenizing_prompt(t_minishell *ms, char *str)
{
	t_list	*token;

	while (*str == ' ' && *str == '\t')
		str++;
	token = ft_lstnew(ft_get_token(&str));
	ms->token = token;
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t')
			str++;
		else
			ft_lstadd_back(&ms->token, ft_lstnew(ft_get_token(&str)));
	}
}

char	*ft_get_token(char **str)
{
	char	*word;

	word = NULL;
	if (**str == '\'' || **str == '"')
		word = ft_getword_quote(str, (char)**str);
	else if (**str == '<' || **str == '>' || **str == '|')
		word = ft_getword_redirection(str, (char)**str);
	else if (**str != ' ')
		word = ft_getword(str);
	return (word);
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
