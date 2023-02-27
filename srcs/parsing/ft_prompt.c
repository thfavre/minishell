/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:55:24 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/22 12:45:47 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_prompt(t_minishell *ms, char *str_prompt)
{
	char	**prompt_split;

	(void) ms;
	prompt_split = ft_split_prompt(str_prompt);
	if (!prompt_split)
		return (NULL);
	return (prompt_split);
}