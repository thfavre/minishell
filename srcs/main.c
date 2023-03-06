/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:10 by mjulliat          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/06 16:03:55 by mjulliat         ###   ########.fr       */
=======
/*   Updated: 2023/03/02 16:02:17 by thfavre          ###   ########.fr       */
>>>>>>> 735b8b9037a82fb679b473b929187d035e3d363d
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_minishell	ms;
	char		*str_prompt;

	(void) ac;
	(void) av;
	ft_init_minishell(&ms, env);
	str_prompt = readline(PROMPT);
	while (str_prompt != NULL)
	{
		ft_parsing(&ms, str_prompt);
		ft_free_token(&ms);
		ft_free_pars(&ms);
		str_prompt = readline(PROMPT);
	}
	//ft_execute(&ms);
	ft_exit(&ms);
	return (0);
}
