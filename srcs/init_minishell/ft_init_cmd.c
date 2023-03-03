/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:48 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/03 15:51:51 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_init_cmd(t_list_token **pars)
{
	t_cmd	*cmd;

	cmd = *(cmd) {};
	if (*pars->type == E_REDIRECTION)
	//need to get the variable that needed to the t_list_cmd
}
