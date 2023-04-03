/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:31 by thomas            #+#    #+#             */
/*   Updated: 2023/04/03 15:37:08 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **env, char **option)
{
	int exit_status;

	exit_status = EXIT_SUCCESS;
	option++; // skip the command name
	while (*option)
	{
		// check if start with alpha and rest isonly_alphanum?
		if (strchr(*option, '-') != NULL || ft_unsetenv(env, *option) == -1)
		{
			ft_putstr_fd("unset: not a valid identifier: \n", 2);
			exit_status = EXIT_FAILURE;
		}
		option++;
	}
	return (exit_status);
}
