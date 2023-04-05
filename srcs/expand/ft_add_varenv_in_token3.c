/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_varenv_in_token3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:59:23 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/05 16:59:33 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lenword_venv(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == ' ')
			break ;
		len++;
	}
	return (len);
}

int	ft_lenword_venv_space(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] != ' ')
			break ;
		len ++;
	}
	return (len);
}

t_list_venv	*ft_lstnew_venv(char *word)
{
	t_list_venv	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(t_list_venv));
	if (!new)
		return (NULL);
	new->word = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	if (!new->word)
		return (NULL);
	while (word[i] != '\0')
	{
		new->word[i] = word[i];
		i++;
	}
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	ft_lstadd_back_venv(t_list_venv **lst, t_list_venv *nw)
{
	t_list_venv	*node;

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

void	ft_lastadd_middle_token(t_list_token *lst, t_list_token *nw)
{
	nw->next = lst->next;
	lst->next = nw;
}
