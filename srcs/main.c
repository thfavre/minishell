
#include "minishell.h"

char	*ft_get_prompt(void)  // TODO put somewhere else (a folder ??) How to name this function ? Is it realy the prompt?
{
	char	*cwd;
	size_t alloc_size;

	alloc_size  = sizeof(*cwd) * 1024;
	cwd = malloc(alloc_size);
	strcpy(cwd, PROMPT_COLOR);
	// TODO what if malloc error ?
	if (getcwd(cwd + ft_strlen(PROMPT_COLOR), alloc_size) == NULL)
		perror("getcwd() error");
	else
	{
		strcat(cwd, COLOR_RESET);
		strcat(cwd, "$ ");
	}
	return (cwd);
}

char	*ft_prompt(void)
{
	char	*prompt_text;
	char	*prompt_output;

	prompt_text = ft_get_prompt();
	prompt_output = readline(prompt_text);
	free(prompt_text);
	return (prompt_output);
}

int main(int ac, char **av, char **env)
{
	t_minishell	ms;
	char		*prompt_output;

	(void)ac;
	(void)av;
	ft_init_minishell(&ms, env); // TODO? make a function init that will init the minishell and signals..?
	ft_init_signals();
	// ft_unsetenv(ms.env, "OLDPWD");
	prompt_output = "ON!";
	while (prompt_output != NULL)
	{
		prompt_output = ft_prompt();
		if (prompt_output && !ft_isspace_only(prompt_output))
		{
			add_history(prompt_output);
			ft_parsing(&ms, prompt_output);
			if (ms.syntax == 0)
				ft_execute(&ms);
			ft_free_token(&ms);
			ft_free_pars(&ms);
		}
		free(prompt_output);
	}
	// ft_putstr_fd("exit\n", 1); // TODO in on STDERROR or STDOUT fd ?
	ft_close(&ms);
	return (EXIT_SUCCESS);
}
