/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:39:34 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 18:03:41 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "struct.h"

# define PROMPT "minishell/"

//		----- ENVIRONMENT_DIRECTORY -----

//		##### Ft_Get_Env.c #####
char	**ft_get_env(char **env);

//		----- PARSING DIRECTORY -----

//		##### Ft_parsing.c #####
void	ft_parsing(t_minishell *ms, char *str_prompt);
char	**ft_pars_prompt(char *str_prompt);

//		##### Ft_Split.c #####
char	**ft_split_prompt(char *s);

//		----- UTILS_DIRECTORY -----

//		##### Utils.c #####
size_t	ft_strlen(char *str);
void	*ft_memset(void *b, int c, size_t len);

//		##### Ft_Memory_Allocation.c #####
void	*ft_calloc(size_t nbyte, size_t size);
void	ft_freesplit(char **strs);

#endif
