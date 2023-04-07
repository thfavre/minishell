
#include "minishell.h"

void	*ft_free_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
			free(env[i++]);
	free(env);
	return (NULL);
}

void	ft_free_path(t_minishell *ms)
{
	// int i;

	// i = 0;
	// while (ms->path[i] != NULL)
	// {
	// 	free(ms->path[i]);
	// 	i++;
	// }
	// free(ms->path);
	(void)ms;
}

void	ft_free_token(t_minishell *ms)
{
	t_list_token *tmp;

	ft_del_heredoc(ms->token);
	while (ms->token != NULL)
	{
		tmp = ms->token;
		ms->token = ms->token->next;
		free(tmp->word);
		free(tmp);
	}
}

void	ft_free_pars(t_minishell *ms)
{
	t_list_cmd *tmp;

	while (ms->cmd != NULL)
	{
		tmp = ms->cmd;
		ms->cmd = ms->cmd->next;
		free(tmp->option);
		free(tmp);
	}
}
