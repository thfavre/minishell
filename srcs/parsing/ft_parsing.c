
#include "minishell.h"

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	t_list_token	*test;

	// TODO skip the first token if it's a (or more) space ?
	// while (str_prompt && *str_prompt == ' ')
	// 	str_prompt++;

	ft_tokenizing_prompt(ms, str_prompt);
	ft_parse_varenv(ms);
	test = ms->token;
	printf("####################\n");
	printf("TOKENIZING PROMPT ->\n");
	while (test != NULL)
	{
		printf("-----\n");
		printf("[%s] <- token\n", test->word);
		printf("{%d} <- type\n", test->type);
		test = test->next;
	}
	ft_parse_token(ms);
}
