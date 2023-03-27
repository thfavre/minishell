/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:31 by thomas            #+#    #+#             */
/*   Updated: 2023/03/27 13:22:14 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **env, char **option)
{
	option++; // skip the command name
	while (*option)
	{
		if (strchr(*option, '-') != NULL || ft_unsetenv(env, *option) == -1)
		{
			ft_putstr_fd("unset: not a valid identifier: \n", 2);
			return (EXIT_FAILURE);
		}
		option++;
	}
	return (EXIT_SUCCESS);
}
