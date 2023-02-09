/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:10 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 18:05:18 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_minishell	ms;
	char		*str_prompt;

	(void) ac;
	(void) av;
	ms.env = env;
	str_prompt = readline(PROMPT);
	while (str_prompt != NULL)
	{
		str_prompt = readline(PROMPT);
		ft_parsing(&ms, str_prompt);
		free(str_prompt);
	}
	return (0);
}
