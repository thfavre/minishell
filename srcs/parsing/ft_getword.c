/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:52:17 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 11:40:28 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getword_redirection(char **str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_redirection(*str, c) + 1);
	while (**str == c)
	{
		word[i] = **str;
		i++;
		(*str)++;
	}
	return (word);
}

char	*ft_getword_quote(char **str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_quote(*str, c) + 1);
	if (**str == c)
	{
		word[i] = (**str);
		(*str)++;
		i++;
	}
	while (**str != '\0' && **str != c)
	{
		word[i] = (**str);
		i++;
		(*str)++;
	}
	if (**str == c)
	{
		word[i] = (**str);
		(*str)++;
	}
	return (word);
}

char	*ft_getword_space(char **str)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_space(*str) + 1);
	while (**str == ' ' || **str == '\t')
	{
		word[i] = (**str);
		i++;
		(*str)++;
	}
	return (word);
}

char	*ft_getword(char **str)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword(*str) + 1);
	while (**str != '\0')
	{
		word[i] = (**str);
		i++;
		(*str)++;
		if (**str == '\'' || **str == '"' || **str == ' ')
			break ;
		else if (**str == '<' || **str == '>' || **str == '|')
			break ;
	}
	return (word);
}
