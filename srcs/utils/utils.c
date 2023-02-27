/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:48:42 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/22 12:13:59 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i != len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (start > ft_strlen(str))
	{
		cpy = malloc(sizeof(char) * 1);
		if (!cpy)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	cpy = ft_calloc(sizeof(char), len + 1);
	if (!cpy)
		return (NULL);
	while (i < len && str[start] != '\0')
	{
		cpy[i] = str[start];
		i++;
		start++;
	}
	return (cpy);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str1[i] != '\0' && str2[i] != '\0' && i < n - 1)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
