/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:10 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/08 21:34:15 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_prompt(void);

int main(int ac, char **av, char **env)
{
	t_minishell ms;
	char *str_prompt;
	char	*prompt;

	(void)ac;
	(void)av;
	ft_init_minishell(&ms, env);
	ft_init_signals();
	prompt = ft_get_prompt(); // TODO find a other way instead of copy paste..
	str_prompt = readline(prompt);
	free(prompt);
	while (str_prompt != NULL)
	{
		if (str_prompt[0] != '\0') // TODO change that, not clean
		{
			add_history(str_prompt);
			ft_parsing(&ms, str_prompt);
			ft_execute(&ms);
			ft_free_token(&ms);
			ft_free_pars(&ms);
			// rl_clear_history();
		}
		prompt = ft_get_prompt();
		str_prompt = readline(prompt);
		free(prompt);
	}
	free(str_prompt);
	ft_exit(&ms);
	return (0);
}

char	*ft_get_prompt(void)  // TODO put somewhere else
{
	char	*cwd;
	size_t alloc_size;

	alloc_size  = sizeof(*cwd) * 1024;
	cwd = malloc(alloc_size);
	cwd[0]='#';
	// TODO what if malloc error ?
	if (getcwd(cwd + 1, alloc_size) == NULL)
		perror("getcwd() error");
	else
		strcat(cwd, "$ ");
}
