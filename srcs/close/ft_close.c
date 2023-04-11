/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:49:27 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:49:33 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close(t_minishell *ms)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	ft_free_env(ms->env);
	rl_clear_history();
}
