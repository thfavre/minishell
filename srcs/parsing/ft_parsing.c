/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:42:30 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 10:51:00 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	t_list	*test;
	char	*prompt;

	prompt = str_prompt;
	ft_tokenizing_prompt(ms, str_prompt);
	free(prompt);
	test = ms->token;
	while (test != NULL)
	{
		printf("[%s]\n", test->word);
		test = test->next;
	}
}
