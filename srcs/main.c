/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:10 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/07 00:45:02 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_minishell ms;
	char *str_prompt;

	(void)ac;
	(void)av;
	ft_init_minishell(&ms, env);
	ft_init_signals();
	str_prompt = readline(PROMPT);
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
		str_prompt = readline(PROMPT);
	}
	free(str_prompt);
	ft_exit(&ms);
	return (0);
}
