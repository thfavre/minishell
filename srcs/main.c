/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:10 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 14:51:53 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*str = "< Makefile 'ls -la' | awk \"{count++} END {print count} > outfile\"";
	char	**all = NULL;
	char 	**split;
	size_t	i;

	(void) ac;
	(void) av;
	(void) all;
	(void) env;
	i = 0;
//	all = ft_get_env(env);
//	str = readline(PROMPT);
	printf("[%s]\n", str);
	split = ft_split(str);
	while (split[i] != NULL)
	{
		printf("[%s]\n", split[i]);
		i++;
	}
	ft_freesplit(split);
	return (0);
}
