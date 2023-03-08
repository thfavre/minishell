/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:42:30 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/08 14:16:43 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	t_list_token	*test;
	char			*prompt;

	prompt = str_prompt;
	ft_tokenizing_prompt(ms, str_prompt);
	free(prompt);
	test = ms->token;
	// printf("####################\n");
	// printf("TOKENIZING PROMPT ->\n");
	while (test != NULL)
	{
		// printf("-----\n");
		// printf("[%s] <- token\n", test->word);
		// printf("{%d} <- type\n", test->type);
		test = test->next;
	}
	ft_parse_varenv(ms);
	ft_parse_token(ms);
}
