/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_varenv_in_token4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:03:58 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 16:53:51 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getword_nodollars(char **str)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_nodollars(*str) + 1);
	if (!word)
		return (NULL);
	while (**str != '\0')
	{
		word[i] = (**str);
		i++;
		(*str)++;
		if (**str == '$')
			break ;
	}
	return (word);
}

t_list_venv	*ft_getwords_dollars(char **str, char ***venv)
{
	t_list_venv	*create;
	char		*word;

	create = NULL;
	word = NULL;
	if (ft_norm(venv, word, &create) != 0)
		ft_print_error_parsing(1);
	if (ft_norm_two(venv, word, &create) != 0)
		ft_print_error_parsing(1);
	while (**str != '\0')
	{
		(*str)++;
		if (**str == '$')
			break ;
	}
	(*venv)++;
	return (create);
}

void	ft_free_init(t_list_venv *init)
{
	t_list_venv	*tmp;

	while (init != NULL)
	{
		tmp = init;
		init = init->next;
		free(tmp);
	}
}
