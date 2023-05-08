/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:55:16 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 18:54:28 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lenword_redirection(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] == c)
		len++;
	return (len);
}

int	ft_lenword_space(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == ' ' || str[len] == '\t')
			len++;
		else
			break ;
	}
	return (len);
}

int	ft_lenword(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '<' || str[len] == '>' || \
			str[len] == '|' || str[len] == ' ')
			break ;
		len++;
	}
	return (len);
}

int	ft_lenword_quote(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
		if (str[len] == c)
		{
			len++;
			break ;
		}
	}
	return (len);
}
