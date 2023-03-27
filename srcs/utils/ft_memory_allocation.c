/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_allocation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:35:59 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 14:36:01 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freesplit(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		i++;
	}
	free (strs);
}
