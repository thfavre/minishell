/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:18:31 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/30 14:03:27 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_init_cmd(t_list_token **pars)
{
	t_cmd	*cmd;
	int		i;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	i = 1;
	*cmd = (t_cmd){};
	cmd->read = 0;
	cmd->write = 1;
	while ((*pars) != NULL)
	{
		if ((*pars)->redirection == E_INFILE || (*pars)->redirection == E_OUTFILE)
			ft_open_files_redirection(pars, cmd);
		else if ((*pars)->type == E_STRING)
			cmd->option = ft_get_option_and_cmd(pars, cmd);
		else if ((*pars)->type == E_PIPE)
		{
			(*pars) = (*pars)->next;
			break ;
		}
		else if ((*pars) != NULL)
			(*pars) = (*pars)->next;
	}
	return (cmd);
}

void	ft_open_files_redirection(t_list_token **pars, t_cmd *cmd)
{
	if (ft_strcmp((*pars)->word, D_INFILE) == 0)
	{
		cmd->read = ft_get_infile(pars);
		if ((*pars) != NULL)
			(*pars) = (*pars)->next;
	}
	else if (ft_strcmp((*pars)->word, D_OUTFILE) == 0)
	{
		cmd->write = ft_get_outfile(pars);
		if ((*pars) != NULL)
			(*pars) = (*pars)->next;
	}
}

char	**ft_get_option_and_cmd(t_list_token **pars, t_cmd *cmd)
{
	size_t	i;
	char	*option_tmp[1024];
	char	**option;

	i = 1;
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
	option_tmp[i] = NULL;
	option = ft_calloc(sizeof(char *), ft_len_option(option_tmp) + 1);
	option = ft_get_option(option, option_tmp);
	return (option);
}

char	**ft_get_option(char **option, char **option_tmp)
{
	size_t	i;

	i = 0;
	while (option_tmp[i] != NULL)
	{
		option[i] = option_tmp[i];
		i++;
	}
	return (option);
}

int	ft_len_option(char **option)
{
	size_t	len;

	len = 0;
	while (option[len] != NULL)
		len++;
	return (len);
}
