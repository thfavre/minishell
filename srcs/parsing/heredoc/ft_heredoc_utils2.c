/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:48:40 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 10:56:16 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp_heredoc(t_list_token *heredoc, char *line)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	if (heredoc->quote != E_NONE)
	{
		j = 1;
		len -= 1;
	}
	while (i < len)
	{
		if (heredoc->word[j] != line[i])
			break ;
		j++;
		i++;
	}
	return (heredoc->word[j] - line[i]);
}

void	ft_open_hd_two(char *all, t_minishell *ms, int fd_heredoc, t_tok *hd)
{
	if (hd->quote == E_NONE)
		ft_replace_varenv_heredoc(&all, ms);
	ft_putstr_fd(all, fd_heredoc);
	free(all);
}
