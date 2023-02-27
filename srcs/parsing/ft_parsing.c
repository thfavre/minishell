/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:42:30 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/22 16:13:04 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	int j = 0;

	ms->prompt_split = ft_prompt(ms, str_prompt);
	while (ms->prompt_split[j] != NULL)
	{
		printf("[%s]\n", ms->prompt_split[j]);
		j++;
	}
	ft_analyse_prompt(ms);
}

void	ft_analyse_prompt(t_minishell *ms)
{
	int	i;

	i = 0;
	while (ms->prompt_split[i] != NULL)
	{
		if (ft_is_token(ms->prompt_split[i]) == 1)
			printf("[%s] is a token\n", ms->prompt_split[i]);
		else if (ft_is_builtins(ms->prompt_split[i]) == 1)
			printf("[%s] is a builtins\n", ms->prompt_split[i]);
		else if (ft_is_varenv(ms->prompt_split[i]) == 1)
			printf("[%s] is a variable of environment\n", ms->prompt_split[i]);
		else if (ft_is_signal(ms->prompt_split[i]) == 1)
			printf("is a signal\n");
		else
			printf("[%s] is a stinrg\n", ms->prompt_split[i]);
		i++;
	}
}
