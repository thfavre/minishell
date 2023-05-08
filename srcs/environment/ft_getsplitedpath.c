/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsplitedpath.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:53:04 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:53:06 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_getsplitedpath(char **env)
{
	char	*unsplited_path;
	char	**splited_path;

	unsplited_path = ft_getenv(env, "PATH");
	if (unsplited_path[0] == '\0')
	{
		free(unsplited_path);
		return (NULL);
	}
	splited_path = ft_split(unsplited_path + 5, ':');
	return (splited_path);
}
