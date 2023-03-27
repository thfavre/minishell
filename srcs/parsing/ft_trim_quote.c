/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:50:58 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 12:51:02 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_trim_quote(t_minishell *ms)
{
	t_list_token	*trim_quote;

	trim_quote = ms->token;
	while (trim_quote != NULL)
	{
		trim_quote->word = ft_remove_quote(&trim_quote->word);
		trim_quote = trim_quote->next;
	}
}

char	*ft_remove_quote(char **str)
{
	char	*trim;
	char	c;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	trim = ft_calloc(sizeof(char), ft_strlen(*str) + 1);
	while (str[0][i] != '\0')
	{
		if (str[0][i] == '"' || str[0][i] == '\'')
		{
			c = str[0][i];
			i++;
			while (str[0][i] != '\0' && str[0][i] != c)
				ft_strcat_trim_quote(trim, *str, &i, &j);
			i++;
		}
		else
			ft_strcat_trim_quote(trim, *str, &i, &j);
	}
	free(*str);
	return (trim);
}

void	ft_strcat_trim_quote(char *s1, char *s2, size_t *i, size_t *j)
{
	s1[*j] = s2[*i];
	(*i)++;
	(*j)++;
}
