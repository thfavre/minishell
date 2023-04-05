/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_varenv_in_token2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:59:54 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/05 17:00:07 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_norm(char ***venv, char *word, t_list_venv *create)
{
	if (***venv != ' ')
	{
		word = ft_get_one_word_venv(venv);
		if (!word)
			return (1);
		create = ft_lstnew_venv(word);
		free(word);
	}
	else
	{
		word = ft_getword_space_venv(venv);
		if (!word)
			return (1);
		create = ft_lstnew_venv(word);
		free(word);
	}
	return (0);
}

int	ft_norm_two(char ***venv, char *word, t_list_venv *create)
{
	while (***venv != '\0')
	{
		if (***venv != ' ')
		{
			word = ft_get_one_word_venv(venv);
			if (!word)
				return (1);
			ft_lstadd_back_venv(&create, ft_lstnew_venv(word));
			free(word);
		}
		else
		{
			word = ft_getword_space_venv(venv);
			if (!word)
				return (1);
			ft_lstadd_back_venv(&create, ft_lstnew_venv(word));
			free(word);
		}
	}
	return (0);
}

char	*ft_get_one_word_venv(char ***venv)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_venv(**venv) + 1);
	if (!word)
		return (NULL);
	while (***venv != '\0')
	{
		word[i] = ***venv;
		(**venv)++;
		i++;
		if (***venv == ' ')
			break ;
	}
	return (word);
}

char	*ft_getword_space_venv(char ***venv)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_venv_space(**venv) + 1);
	if (!word)
		return (NULL);
	while (***venv == ' ')
	{
		word[i] = ***venv;
		(**venv)++;
		i++;
	}
	return (word);
}

int	ft_lenword_nodollars(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '$')
			break ;
		len++;
	}
	return (len);
}
