/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:11:53 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 15:17:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_prompt_text(void)
{
	char	*cwd;
	size_t	alloc_size;

	alloc_size = sizeof(*cwd) * MAXPATHLEN + \
		ft_strlen(PROMPT_COLOR) + ft_strlen(COLOR_RESET) + 3;
	cwd = malloc(alloc_size);
	strcpy(cwd, PROMPT_COLOR);
	if (getcwd(cwd + ft_strlen(PROMPT_COLOR), MAXPATHLEN) == NULL)
		perror("getcwd() error");
	else
	{
		strcat(cwd, COLOR_RESET);
		strcat(cwd, "$ ");
	}
	return (cwd);
}

char	*ft_prompt(void)
{
	char	*prompt_text;
	char	*prompt_output;

	prompt_text = ft_prompt_text();
	prompt_output = readline(prompt_text);
	free(prompt_text);
	return (prompt_output);
}
