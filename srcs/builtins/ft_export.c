/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/11 01:45:58 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_export(t_minishell *ms, char **option)
{
	char	**new_env;

	option++; // skip the command name
	while (*option)
	{
		if (strchr(*option, '=') != NULL)
		{
			new_env = ft_putenv(ms->env, *option);
			if (new_env != NULL)
			{
				ft_free_env(ms->env);
				ms->env = new_env;
			}
			// else
			// 	ft_putstr_fd("export: not a valid identifier: \n", 2);
		}
		// else
		// {
		// 	// ft_putstr_fd("export: not a valid identifier: \n", 2); // what if there is no '=' ?
		// }
		option++;
	}
}
