/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:48 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/06 16:23:58 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_init_cmd(t_list_token **pars, int *fd_pipe)
{
	t_cmd	*cmd;
	char	*option_tmp[1024];
	int		i;

	(void) fd_pipe;
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	i = 1;	
	*cmd = (t_cmd) {};
	cmd->read = 0;
	cmd->write = 1;
	while ((*pars) != NULL)
	{
		if ((*pars)->type == E_REDIRECTION)
		{
			if (ft_strcmp((*pars)->word, D_INFILE) == 0)
			{
				cmd->read = ft_get_infile(pars);
				(*pars) = (*pars)->next;
			}
			else if (ft_strcmp((*pars)->word, D_OUTFILE) == 0)
			{
				cmd->write = ft_get_outfile(pars);
				(*pars) = (*pars)->next;
			}
		}
		else if ((*pars)->type == E_STRING)
		{
			cmd->cmd = (*pars)->word;
			option_tmp[0] = cmd->cmd;
			(*pars) = (*pars)->next;
			while ((*pars) != NULL)
			{
				if ((*pars)->type == E_PIPE || (*pars)->type == E_REDIRECTION)
					break ;
				else if ((*pars)->type == E_STRING)
				{	
					option_tmp[i] = (*pars)->word;
					i++;
				}
				if ((*pars) != NULL)
					(*pars) = (*pars)->next;
			}
		}
		else if ((*pars)->type == E_PIPE)
		{
			(*pars) = (*pars)->next;
			break ;
		}
		else if ((*pars) != NULL)
			(*pars) = (*pars)->next;
	}
	option_tmp[i] = NULL;
	i = 0;
	while (option_tmp[i] != NULL)
		i++;
	cmd->option = ft_calloc(sizeof(char *), i + 1);
	if (!cmd->option)
		return (NULL);
	i = 0;
	while (option_tmp[i] != NULL)
	{
		cmd->option[i] = option_tmp[i];
		i++;
	}
	return (cmd);
}
