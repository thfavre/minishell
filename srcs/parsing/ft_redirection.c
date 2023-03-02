/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:20:47 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 15:39:04 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_redirection(char *str)
{
	if (ft_strcmp(str, D_INFILE) == 0)
		return (1);
	else if (ft_strcmp(str, D_OUTFILE) == 0)
		return (2);
	else if (ft_strcmp(str, D_HEREDOC) == 0)
		return (3);
	else if (ft_strcmp(str, D_APPEND) == 0)
		return (4);
	return (0);
}

int	ft_get_infile(t_list *pars)
{
	int	fd;

	pars = pars->next;
	while (pars->word[0] == ' ' || pars->word[0] == '\t')
		pars = pars->next;
	fd = open(pars->word, O_RDONLY);
	return (fd);
}

int	ft_get_outfile(t_list *pars)
{
	int	fd;

	pars = pars->next;
	while (pars->word[0] == ' ' || pars->word[0] == '\t')
		pars = pars->next;
	fd = open(pars->word, O_TRUNC | O_CREAT | O_RDWR, 0644);
	return (fd);
}
