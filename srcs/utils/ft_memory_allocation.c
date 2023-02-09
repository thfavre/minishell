/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_allocation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:50:34 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 14:46:10 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t nbyte, size_t size)
{
	void	*cal;

	cal = malloc(nbyte * size);
	if (!cal)
		return (NULL);
	ft_memset(cal, 0, nbyte * size);
	return (cal);
}

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
