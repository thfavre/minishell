/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/07 00:39:29 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// The longer answer is that in bash, commands in a pipeline are each executed in a subshell. Since cd is a shell builtin, it only affects the shell it's executed in. If you cd within a subshell, the effect will disappear when the subshell exits.
void ft_cd_command(char *path)
{
	if (path == NULL)
		chdir(getenv("HOME"));
	else if (chdir(path) != 0)
		perror("chdir() error");
}
