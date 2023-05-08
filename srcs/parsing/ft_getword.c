/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:55:50 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 17:18:38 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getword_redirection(char **str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_redirection(*str, c) + 1);
	if (!word)
		return (NULL);
	while (**str == c)
	{
		word[i] = **str;
		i++;
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
	if (!word)
		return (NULL);
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
	if (!word)
		return (NULL);
	while (**str != '\0')
	{
		if (**str == '<' || **str == '>' || **str == '|' || **str == ' ')
			break ;
		else if (**str == '\'' || **str == '"')
			break ;
		else
		{
			word[i] = (**str);
			(*str)++;
			i++;
		}
	}
	return (word);
}

char	*ft_getword_quote(char **str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_quote(*str, c) + 1);
	if (!word)
		return (NULL);
	word[i] = (**str);
	i++;
	(*str)++;
	while (**str != '\0')
	{
		word[i] = (**str);
		if (**str == c)
			break ;
		i++;
		(*str)++;
	}
	if (**str == c)
		(*str)++;
	return (word);
}
