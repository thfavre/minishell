/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:50:35 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/30 12:07:09 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H	
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);

void	*ft_calloc_gnl(size_t count, size_t nbyte);
char	*ft_strchr_gnl(const char *s, char c);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
size_t	ft_stlen(const char *str);
char	*ft_free_and_join(char *buffer, char *str);

#endif
