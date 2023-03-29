/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:53:58 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 17:58:22 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_list_token(t_list_token *token)
{
	t_list_token	*test;

	test = token;
	printf("\nPROMPT TOKENIZED ->\n");
	while (test != NULL)
	{
		printf("-----\n");
		printf("[%s] <- token\n", test->word);
		printf("{%d} <- type\n", test->type);
		printf("{%d} <- quote\n", test->quote);
		test = test->next;
	}
}

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	ft_tokenizing_prompt(ms, str_prompt);
	ft_expand(ms);
	if (ft_syntax(ms) == 0)
	{
		ft_trim_quote(ms);
		ft_join_token(ms->token);
		ft_parse_token(ms);
	}
	ft_print_list_token(ms->token);
}
// Bonus : Expand the wildcard pattern
