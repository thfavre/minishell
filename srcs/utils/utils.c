/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:48:42 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/10 18:02:44 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'|| c == '\v' \
		|| c == '\f' || c == '\r')
		return (true);
	return (false);
}

bool ft_isspace_only(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (false);
		str++;
	}
	return (true);
}
