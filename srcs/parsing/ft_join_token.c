/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:59:56 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 13:12:52 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_join_token(t_list_token *lst)
{
	char			*new_word;
	int				i;
	int				j;

	while (lst != NULL)
	{
		if (ft_is_joinable(lst) == 1)
			lst = lst->next;
		else if (lst->next != NULL && *lst->word != ' ' && \
			*lst->next->word != ' ')
		{
			i = 0;
			j = 0;
			new_word = ft_calloc(sizeof(char), \
				ft_strlen(lst->word) + ft_strlen(lst->next->word) + 1);
			//	TODO malloc error
			ft_strcat_join_token(new_word, lst->word, &i, &j);
			i = 0;
			ft_strcat_join_token(new_word, lst->next->word, &i, &j);
			ft_free_and_get_new_word(lst, new_word);
		}
		else
			lst = lst->next;
	}
}

int	ft_is_joinable(t_list_token *lst)
{
	if (lst->next != NULL)
	{
		if (lst->type == E_REDIRECTION || lst->type == E_PIPE)
			return (1);
		else if (lst->type == E_STRING && lst->next->type == E_REDIRECTION)
			return (1);
		else if (lst->type == E_STRING && lst->next->type == E_PIPE)
			return (1);
	}
	return (0);
}

void	ft_strcat_join_token(char *s1, char *s2, int *i, int *j)
{
	while (s2[*i] != '\0')
	{
		s1[*j] = s2[*i];
		(*i)++;
		(*j)++;
	}
}

void	ft_free_and_get_new_word(t_list_token *lst, char *new_word)
{
	t_list_token	*tmp;

	free(lst->word);
	lst->word = new_word;
	tmp = lst->next;
	lst->next = tmp->next;
	free(tmp->word);
	free(tmp);
}
