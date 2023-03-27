/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:28:22 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 12:29:07 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_name_varenv(char *str)
{
	char	*var_env;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == '$' || str[i] == ' ' || str[i] == '\'')
			break ;
		if (ft_isalpha(str[i]) == false)
			break ;
		len++;
		i++;
	}
	var_env = ft_calloc(sizeof(char), len + 1);
	if (!var_env)
		return (NULL);
	i = 0;
	while (i < len)
	{
		var_env[i] = str[i];
		i++;
	}	
	return (var_env);
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
