/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:28:22 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/28 15:42:09 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_name_varenv(char *str)
{
	char	*var_env;
	size_t	len;
	size_t	i;

	i = 0;
	if (ft_is_question_mark(str) == 1)
		len = 1;
	else
		len = ft_len_venv(str);
	var_env = ft_calloc(sizeof(char), len + 1);
	if (!var_env)
		return (NULL);
	while (i < len)
	{
		var_env[i] = str[i];
		i++;
	}	
	return (var_env);
}

int	ft_is_question_mark(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '?' && str[i + 1] == '\0')
		return (1);
	return (0);
}

int	ft_len_venv(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '"' || str[len] == '$' || \
				str[len] == ' ' || str[len] == '\'')
			break ;
		if (ft_isalpha(str[len]) == false)
			break ;
		len++;
	}
	return (len);
}

int	ft_token_got_varenv(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	ft_nbr_varenv(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			count++;
		i++;
	}
	return (count);
}
