
#include "minishell.h"

void	ft_parse_token(t_minishell *ms)
{
	t_list_token	*pars;
	t_list_cmd		*test;

	pars = ms->token;
	printf("####################\n");
	printf("parsing token ->\n");
	// printf("####################\n");
	// printf("parsing token ->\n");
	while (pars != NULL)
	{
		if (!ms->cmd)
		{
			printf("FIRST CMD\n");
			ms->cmd = ft_lstnew_cmd(ft_init_cmd(&pars, ms->fd_pipe));
		}
		else
		{
			// printf("OTHER CMD\n");
			ft_lstadd_back_cmd(&ms->cmd, ft_lstnew_cmd(ft_init_cmd(&pars, ms->fd_pipe)));
		}
	}
	test = ms->cmd;
	int	j = 0;
	int	i = 0;
	while (test != NULL)
	{
		printf(" --- cmd[%d] ---\n", j);
		printf("[%s] <- cmd\n", test->cmd);
		while (test->option[i] != NULL)
		{
			printf("[%s] <- option[%d]\n", test->option[i], i);
			i++;
		}
		i = 0;
		printf("[%d] <- fd_read\n", test->fd_read);
		printf("[%d] <- fd_write\n", test->fd_write);
		j++;
		test = test->next;
	}
}
