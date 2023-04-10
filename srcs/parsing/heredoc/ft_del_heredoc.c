/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:56:36 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 17:17:47 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_heredoc(t_list_token *token)
{
	while (token != NULL)
	{
		if (ft_strncmp(token->word, ".heredoc", ft_strlen(".heredoc")) == 0)
			ft_del_file(token->word);
		token = token->next;
	}
}

void	ft_del_file(char *str)
{
	char	**option;
	pid_t	pid_fork;

	option = ft_calloc(sizeof(char *), 3);
	if (!option)
		exit(printf("Error Malloc\n") + 247);
	option[0] = ft_strdup("/bin/rm");
	if (!option[0])
		exit(printf("Error Malloc\n") + 247);
	option[1] = ft_strdup(str);
	if (!option[1])
		exit(printf("Error Malloc\n") + 247);
	if (access(str, F_OK) == 0)
	{
		pid_fork = fork();
		if (pid_fork == 0)
			execve(option[0], option, NULL);
	}
	free(option[1]);
	free(option[0]);
	free(option);
}
