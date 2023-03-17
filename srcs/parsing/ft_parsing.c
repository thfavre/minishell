
#include "minishell.h"

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	t_list_token	*test;

	// TODO skip the first token if it's a (or more) space ?
	// while (str_prompt && *str_prompt == ' ')
	// 	str_prompt++;

	ft_tokenizing_prompt(ms, str_prompt);
	ft_parse_varenv(ms);
	ft_trim_quote(ms);
	ft_join_token(ms->token);
	test = ms->token;
	printf("####################\n");
	printf("PROMPT TOKENIZED ->\n");
	while (test != NULL)
	{
		printf("-----\n");
		printf("[%s] <- token\n", test->word);
		printf("{%d} <- type\n", test->type);
		printf("{%d} <- quote\n", test->quote);
		test = test->next;
	}
	ft_parse_token(ms);
	// Bonus : Expand the wildcard pattern
}
