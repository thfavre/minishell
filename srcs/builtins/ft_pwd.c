/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:31 by thomas            #+#    #+#             */
/*   Updated: 2023/03/08 21:14:29 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_pwd(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	printf("%s\n", cwd);
}