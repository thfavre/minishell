/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:42:30 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 18:47:44 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	char	**split_prompt;

	ms->path = ft_get_path(ms);
	split_prompt = ft_get_prompt(str_prompt);
	if (!split_prompt)
	{
		free(str_prompt);
		exit(1);
	}
	int	i = 0;
	while (ms->path[i] != NULL)
	{
		printf("%s\n", ms->path[i]);
		i++;
	}
}

char	**ft_get_prompt(char *str_prompt)
{
	char	**prompt_split;

	prompt_split = ft_split_prompt(str_prompt);
	if (!prompt_split)
		return (NULL);
	return (prompt_split);
}