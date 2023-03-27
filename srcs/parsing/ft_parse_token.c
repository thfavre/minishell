
#include "minishell.h"

void	ft_parse_token(t_minishell *ms)
{
	t_list_token	*pars;
	t_list_cmd		*test;
	t_list_token	*start;

	start = ms->token;
	pars = ms->token;
/*	printf("####################\n");
	printf("parsing token ->\n");*/
	while (pars != NULL)
	{
		if (!ms->cmd)
			ms->cmd = ft_lstnew_cmd(ft_init_cmd(&pars));
		else
			ft_lstadd_back_cmd(&ms->cmd, ft_lstnew_cmd(ft_init_cmd(&pars)));
	}
	test = ms->cmd;
	int	j = 0;
	int	i = 0;
	while (test != NULL)
	{
	//	printf(" --- cmd[%d] ---\n", j);
	//	printf("[%s] <- cmd\n", test->cmd);
		while (test->option[i] != NULL)
		{
		//	printf("[%s] <- option[%d]\n", test->option[i], i);
			i++;
		}
		i = 0;
	//	printf("[%d] <- fd_read\n", test->fd_read);
	//	printf("[%d] <- fd_write\n", test->fd_write);
		j++;
		test = test->next;
	}
	ms->token = start;
}
