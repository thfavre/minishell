/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:10:35 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 15:20:21 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_exit_status;

int	main(int ac, char **av, char **env)
{
	t_minishell	ms;
	char		*prompt_output;

	(void)ac;
	(void)av;
	ft_init_minishell(&ms, env);
	prompt_output = "ON!";
	while (prompt_output != NULL)
	{
		ft_init_signals(ft_handle_signals_prompt);
		prompt_output = ft_prompt();
		ft_init_signals(ft_handle_signals_execution);
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
	ft_close(&ms);
	return (EXIT_SUCCESS);
}
