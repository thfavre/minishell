/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:35:11 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 15:31:18 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_minishell(t_minishell *ms, char **env)
{
	*ms = (t_minishell){};
	ms->env = ft_initenv(env);
	ms->last_exit_status = EXIT_SUCCESS;
	ms->syntax = 0;
}
