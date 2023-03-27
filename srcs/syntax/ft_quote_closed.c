/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:09:23 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 12:17:34 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quote_closed(char *str)
{
	size_t	i;
	int		open;

	i = 0;
	open = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '"')
			open = ft_quote_is_open(str, str[i], &i);
		else
			i++;
	}
	if (open == 1)
		return (1);
	return (0);
}

int	ft_quote_is_open(char *str, char c, size_t *i)
{
	(*i)++;
	while (str[*i] != '\0')
	{
		if (str[*i] == c)
		{
			(*i)++;
			return (0);
		}
		(*i)++;
	}
	return (1);
}
