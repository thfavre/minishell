/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsplitedpath.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:17:45 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/08 14:41:33 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	** ft_getsplitedpath(char **env)
{
	char	*unsplited_path;
	char	**splited_path;

	unsplited_path = ft_getenv(env, "PATH");
	if (unsplited_path == NULL)
		return (NULL);
	splited_path = ft_split(unsplited_path + 5, ':');
	free(unsplited_path);
	return (splited_path);
}
