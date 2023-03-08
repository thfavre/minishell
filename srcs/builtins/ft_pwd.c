/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:31 by thomas            #+#    #+#             */
/*   Updated: 2023/03/08 16:43:48 by thfavre          ###   ########.fr       */
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
