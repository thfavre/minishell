/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:55:50 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/07 20:02:07 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_exit(t_minishell *ms)
{
	ft_free_env(ms->env);
	ft_free_path(ms); // TODO change ms to ms->path to be more specific (or remove this and replace with ft_getenv("PATH") when implemented)
	printf("exit\n");
}
