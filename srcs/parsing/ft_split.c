/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:21:23 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 17:05:34 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_next_delimiter(char **s, int c)
{
	(*s)++;
	while (**s != c && **s != '\0')
		(*s)++;
	if (**s)
		(*s)++;
}

static int	ft_wordcount(char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == '\'')
		{
			count++;
			ft_next_delimiter(&s, '\'');
		}
		else if (*s != ' ')
		{
			count++;
			ft_next_delimiter(&s, ' ');
		}
		else
			s++;
	}
	return (count);
}

/// @brief allocates memory and returns a string using 'c' as delimiter.
/// @param s pointer to the start of the word.
/// @param c the delimiter character.
/// @return the new string.
static char	*ft_getword(char **s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	if (**s == c)
		(*s)++;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	word = (char *)ft_calloc(i + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while ((**s) && (**s) != c)
	{
		word[i] = (**s);
		i++;
		(*s)++;
	}
	if (**s)
		(*s)++;
	return (word);
}

char	**ft_split_prompt(char *s)
{
	int		i;
	char	**strs;

	strs = (char **)ft_calloc(ft_wordcount(s) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == '\'')
			strs[i++] = ft_getword(&s, '\'');
		else if (*s == '"')
			strs[i++] = ft_getword(&s, '"');
		else if (*s != ' ')
			strs[i++] = ft_getword(&s, ' ');
/*		if (!strs[i - 1])
		{
			ft_freesplit(strs);
			return (NULL);
		}*/
		if (*s == ' ')
			s++;
	}
	return (strs);
}
