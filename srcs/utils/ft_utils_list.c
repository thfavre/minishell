/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:36:04 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/05 11:00:51 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_cmd	*ft_lstnew_cmd(t_cmd *cmd)
{
	t_list_cmd	*new;

	new = malloc(sizeof(t_list_cmd));
	if (!new)
		return (NULL);
	new->cmd = cmd->cmd;
	new->option = cmd->option;
	new->fd_read = cmd->read;
	new->fd_write = cmd->write;
	new->next = NULL;
	free(cmd);
	return (new);
}

t_list_token	*ft_lstnew_token(char *word)
{
	t_list_token	*new;

	new = malloc(sizeof(t_list_token));
	if (!new)
		return (NULL);
	new->word = word;
	new->type = ft_get_token_type(word);
	new->red = ft_which_redirection(word);
	new->quote = ft_token_is_quoted(word);
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	ft_lstadd_back_cmd(t_list_cmd **lst, t_list_cmd *nw)
{
	t_list_cmd	*node;

	node = *lst;
	if (node == NULL)
		node = nw;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = nw;
	}
}

void	ft_lstadd_back_token(t_list_token **lst, t_list_token *nw)
{
	t_list_token	*node;

	node = *lst;
	if (node == NULL)
		node = nw;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = nw;
		nw->previous = node;
	}
}
