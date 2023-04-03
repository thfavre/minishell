/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:59:53 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/30 12:05:50 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_gnl(size_t size, size_t nbyte)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(size * nbyte);
	if (!str)
		return (NULL);
	while (i < size * nbyte)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_stlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	str = ft_calloc_gnl((ft_stlen(s1) + ft_stlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	return (str);
}

char	*ft_strchr_gnl(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_free_and_join(char *buffer, char *str)
{
	char	*tmp;

	tmp = ft_strjoin_gnl(str, buffer);
	free(str);
	return (tmp);
}
