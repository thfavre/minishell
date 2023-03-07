/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:39:34 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/07 23:10:51 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

#include "struct.h"
#include "define.h"

#define PROMPT "minishell/"

//		----- ENVIRONMENT DIRECTORY -----

//		##### Ft_initenv.c #####
char **ft_initenv(char **env);

//		##### Ft_setenv.c #####
int	ft_setenv(t_minishell *ms, char *key, char *value, int overwrite);

//		##### Ft_unsetenv.c #####
int	ft_unsetenv(char **env, char *key);

//		##### Ft_getenv.c #####
char	*ft_getenv(char **env, char *key);

//		##### Ft_Get_Path.c #####
char **ft_get_path(t_minishell *ms);

//		----- EXIT DIRECTORY -----

//		##### Ft_Exit.c #####
void ft_exit(t_minishell *ms);

//		##### Ft_Free_Allocation.c #####
void *ft_free_env(char **env);
void ft_free_path(t_minishell *ms);
void ft_free_token(t_minishell *ms);
void ft_free_pars(t_minishell *ms);

//		----- INIT_DATA DIRECTORY -----

//		##### Ft_Init_Data.c #####
void ft_init_minishell(t_minishell *ms, char **env);

//		##### Ft_Init_Cmd.c #####
t_cmd *ft_init_cmd(t_list_token **pars, int *fd_pipe);

//		----- PARSING DIRECTORY -----

//		##### Ft_parsing.c #####
void ft_parsing(t_minishell *ms, char *str_prompt);

//		##### Ft_Parse_Token.c #####
void ft_parse_token(t_minishell *ms);
int ft_get_nbcmd(t_list_token *pars);

//		##### Ft_Redirection.c #####
int ft_get_infile(t_list_token **pars);
int ft_get_outfile(t_list_token **pars);

//		##### Ft_Getword.c #####
char *ft_getword_redirection(char **str, char c);
char *ft_getword_quote(char **str, char c);
char *ft_getword_space(char **str);
char *ft_getword(char **str);
//
//		##### Ft_Lenword.c #####
int ft_lenword_redirection(char *str, char c);
int ft_lenword_quote(char *str, char c);
int ft_lenword_space(char *str);
int ft_lenword(char *str);

//		##### Ft_Token_Type.c #####
int ft_is_redirection(char *str);
int ft_is_builtins(char *str);
int ft_is_pipe(char *str);
int ft_is_space(char *str);

//		##### Ft_Tokenizing_Prompt.c #####
void ft_tokenizing_prompt(t_minishell *ms, char *str);
char *ft_get_token(char **str);
int ft_get_token_type(char *str);

//		----- SIGNAL DIRECTORY -----

//		##### Ft_handle_signals.c #####
void ft_handle_signals(int signo);

//		##### Ft_init_signals.c #####
void ft_init_signals();

//		----- EXECUTE DIRECTORY -----

//		##### Ft_execute.c #####
void ft_execute(t_minishell *ms);

//		----- BUILTINS DIRECTORY -----

//		##### Ft_env.c #####
void	ft_env(char **env);

//		----- UTILS DIRECTORY -----

//		##### Ft_Memory_Allocation.c #####
void *ft_calloc(size_t nbyte, size_t size);
void ft_freesplit(char **strs);

//		##### Ft_Split.c #####
char **ft_split(char *str, char c);

//		##### Ft_Utils_List.c #####
t_list_cmd *ft_lstnew_cmd(t_cmd *cmd);
t_list_token *ft_lstnew_token(char *word);
void ft_lstadd_back_cmd(t_list_cmd **lst, t_list_cmd *nw);
void ft_lstadd_back_token(t_list_token **lst, t_list_token *nw);

//		##### Utils.c #####
size_t ft_strlen(char *str);
void *ft_memset(void *b, int c, size_t len);
char *ft_substr(char *str, size_t start, size_t len);
int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
