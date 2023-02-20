/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:55:24 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/20 14:03:00 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt(t_minishell *ms, char *str_prompt)
{
	ms->prompt_split = ft_split_prompt(str_prompt);
	/*if (!ms->prompt_split)
		return (NULL);*/
	ms->nb_cmd = ft_count_cmd(ms);
}

int	ft_count_cmd(t_minishell *ms)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (ms->prompt_split[i] != NULL)
	{
		if (ft_is_cmd(ms, ms->prompt_split[i]) == 1)
		{
			printf("{%s} is a command\n", ms->prompt_split[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_is_cmd(t_minishell *ms, char *str)
{
	char	path_cmd[1000];
	int		i;
	int		j;
	int		k;

	i = 0;
	while (ms->path[i] != NULL)
	{
		j = 0;
		k = 0;
		while (ms->path[i][j] != '\0')
		{
			path_cmd[j] = ms->path[i][j];
			j++;
		}
		path_cmd[j] = '/';
		j++;
		while (str[k] != '\0')
		{
			path_cmd[j] = str[k];
			j++;
			k++;
		}
		path_cmd[j] = '\0';
		if (access(path_cmd, X_OK) == 0)
			return (1);
		i++;
	}
	return (0);
}
