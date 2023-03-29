/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:35:11 by mjulliat          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/27 15:46:49 by thfavre          ###   ########.fr       */
=======
/*   Updated: 2023/03/27 16:08:27 by mjulliat         ###   ########.fr       */
>>>>>>> 205d87d9df6d232a38589b6c004c42974e71d2ce
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
