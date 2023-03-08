/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/08 21:31:37 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_cd(char **paths)
{
	if (paths[1] == NULL)
		chdir(getenv("HOME"));
	else if (chdir(paths[1]) != 0)
		printf("cd: %s: %s ()\n", paths[1], strerror(errno));
		//perror("chdir() error");
}
