/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/03/27 14:35:11 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/29 13:52:19 by thfavre          ###   ########.fr       */
=======
/*   Created: 2023/03/29 14:20:50 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/29 14:20:53 by mjulliat         ###   ########.fr       */
>>>>>>> here_doc
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_minishell(t_minishell *ms, char **env)
{
	*ms = (t_minishell){};
	ms->env = ft_initenv(env);
	last_exit_status = EXIT_SUCCESS;
	ms->syntax = 0;
}
