/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:11:26 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/03 11:27:11 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew_token(char *word)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->word = word;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*node;

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
