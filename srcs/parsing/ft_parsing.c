
#include "minishell.h"

void	ft_parsing(t_minishell *ms, char *str_prompt)
{
	t_list_token	*test;
	char			*prompt;

	prompt = str_prompt;
	ft_tokenizing_prompt(ms, str_prompt);
	free(prompt);
	ft_parse_varenv(ms);
	test = ms->token;
	printf("####################\n");
	printf("PROMPT TOKENIZED ->\n");
	while (test != NULL)
	{
		printf("-----\n");
		printf("[%s] <- token\n", test->word);
		printf("{%d} <- type\n", test->type);
		test = test->next;
	}
	ft_parse_token(ms);
}
