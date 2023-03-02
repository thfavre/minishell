/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:10 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 15:52:12 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_minishell	ms;
	char		*str_prompt;

	(void) ac;
	(void) av;
	ft_init_data(&ms, env);
	str_prompt = readline(PROMPT);
	while (str_prompt != NULL)
	{
		ft_parsing(&ms, str_prompt);
		ft_free_token(&ms);
		str_prompt = readline(PROMPT);
	}
	//ft_execute(&ms);
	ft_exit(&ms);
	return (0);
}
