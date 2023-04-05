/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:53:58 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/05 15:58:58 by mjulliat         ###   ########.fr       */
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
		printf("{%d} <- redirection\n", test->red);
		printf("{%d} <- quote\n", test->quote);
		test = test->next;
	}
}

void	ft_print_error_parsing(int code_error)
{
	if (code_error == 1)
	{
		printf("Error Malloc in parsing\n");
		exit (0);
	}
}

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	int	code_error;

	ms->syntax = 0;
	ft_tokenizing_prompt(ms, str_prompt);
	ft_heredoc(ms);
	code_error = 0;
	if (ms->syntax == 0)
	{
		code_error = ft_expand(ms);
		if (ft_syntax(ms) == 0)
		{
			ft_trim_quote(ms);
			code_error = ft_join_token(ms->token);
			ft_parse_token(ms);
		}
	}
	if (code_error != 0)
		ft_print_error_parsing(code_error);
	if (DEBUG == 1)
		ft_print_list_token(ms->token);
}
// Bonus : Expand the wildcard pattern
