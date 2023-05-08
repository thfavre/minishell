/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:41 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 18:08:55 by mjulliat         ###   ########.fr       */
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
# include <signal.h>
# include <errno.h>
# include <stdbool.h>
# include <termios.h>
# include <sys/param.h>

# include "struct.h"
# include "define.h"
# include "../srcs/libft/libft.h"

//###########################################//
//		===== BUILTINS DIRECTORY =====
//###########################################//
//
//		----- Ft_env.c -----
int		ft_env(char **env);

//		----- Ft_pwd.c -----
int		ft_pwd(void);

//		----- Ft_cd.c -----
int		ft_cd(t_minishell *ms, char **paths);

//		----- Ft_unset.c -----
int		ft_unset(char **env, char **option);

//		----- Ft_echo.c -----
int		ft_echo(char **option);

//		----- Ft_exit.c -----
void	ft_exit(t_minishell *ms, char **option);

//		----- Ft_export.c -----
int		ft_export(t_minishell *ms, char **option);

//###########################################//
//		===== CLOSE DIRECTORY =====
//###########################################//
//
//		----- Ft_close.c -----
void	ft_close(t_minishell *ms);

//		----- Ft_Free_Allocation.c -----
void	*ft_free_env(char **env);
void	ft_free_token(t_minishell *ms);
void	ft_free_pars(t_minishell *ms);

//###########################################//
//		===== ENVIRONMENT DIRECTORY =====
//###########################################//
//
//		----- Ft_initenv.c -----
char	**ft_initenv(char **env);

//		----- Ft_setenv.c -----
int		ft_setenv(t_minishell *ms, char *key, char *value);

//		----- Ft_unsetenv.c -----
void	ft_unsetenv(char **env, char *key);

//		----- Ft_putenv.c -----
char	**ft_putenv(char **env, char *string);

//		----- Ft_getenv.c -----
char	*ft_getenv(char **env, char *key);

//		----- Ft_Get_Path.c -----
char	**ft_get_path(t_minishell *ms);
char	**ft_getsplitedpath(char **env);

//###########################################//
//		===== EXECUTE DIRECTORY =====
//###########################################//
//
//		----- Ft_execute.c -----
void	ft_execute(t_minishell *ms);

//		----- Ft_execute_builtin.c -----
void	ft_execute_external(char **env, struct s_list_cmd *cmd);

//		----- Ft_execute_cmd.c -----
void	ft_execute_cmd(t_minishell *ms);

//		----- Ft_execute_cmds.c -----
void	ft_execute_cmds(t_minishell *ms);

//		----- Ft_execute_external.c -----
int		ft_execute_builtin(t_minishell *ms, struct s_list_cmd *cmd);

//###########################################//
//		===== EXPAND DIRECTORY =====
//###########################################//
//
//		----- Ft_Add_Varenv_In_Token.c -----
int		ft_add_varenv_in_token(t_list_token *token, char **env, size_t i);
void	ft_add_varenv_in_list(t_list_token *token, char **venv);
t_venv	*ft_getwords_venv(char *word, char **venv);
void	ft_join_word_venv(t_list_venv *lst);
void	ft_free_excess(t_list_venv *lst, char *new_word);

//		----- Ft_Add_Varenv_In_Token2.c -----
char	*ft_get_one_word_venv(char ***venv);
char	*ft_getword_space_venv(char ***venv);
int		ft_lenword_nodollars(char *str);
int		ft_norm(char ***venv, char *word, t_list_venv **create);
int		ft_norm_two(char ***venv, char *word, t_list_venv **create);

//		----- Ft_Add_Varenv_In_Token3.c -----
int		ft_lenword_venv(char *str);
int		ft_lenword_venv_space(char *str);
t_venv	*ft_lstnew_venv(char *word);
void	ft_lstadd_back_venv(t_list_venv **lst, t_list_venv *nw);
void	ft_lastadd_middle_token(t_list_token *lst, t_list_token *nw);

//		----- Ft_Add_Varenv_In_Token4.c -----
char	*ft_getword_nodollars(char **str);
t_venv	*ft_getwords_dollars(char **str, char ***venv);

//		----- Ft_Expand.c -----
int		ft_expand(t_minishell *ms);
int		ft_norm_expand(t_tok *token, char ***venv, char **env, size_t i);
void	ft_skip_dollars_alone(t_minishell *ms);
int		ft_dollars_alone(char *str);
void	ft_free_empty_venv(char **venv);

//		----- Ft_Expand_Utils.c -----
char	*ft_get_name_varenv(char *str);
int		ft_token_got_varenv(char *str);
int		ft_nbr_varenv(char *str);
int		ft_len_venv(char *str);
int		ft_is_question_mark(char *str);

//		----- Ft_Replace_Varenv.c -----
int		ft_replace_varenv(t_list_token *token, char **env, size_t i);
void	ft_strcat_expand(char *s1, char *s2, size_t *i, size_t *j);
void	ft_put_new_word(char *var_env, char *new_word, size_t *i, size_t *j);
char	*ft_get_new_word(char *w, char **var_env);
int		ft_len_new_word(char *w, char **var_env);

//###########################################//
//		===== INIT_MINISHELL DIRECTORY =====
//###########################################//
//
//		----- Ft_Init_Data.c -----
void	ft_init_minishell(t_minishell *ms, char **env);

//		----- Ft_Init_Cmd.c -----
t_cmd	*ft_init_cmd(t_list_token **pars);
void	ft_open_files_redirection(t_list_token **pars, t_cmd *cmd);
char	**ft_get_option_and_cmd(t_list_token **pars, t_cmd *cmd);
char	**ft_get_option(char **option, char **option_tmp);
int		ft_len_option(char **option);

//		----- Ft_Redirection.c -----
int		ft_get_infile(t_list_token **pars);
int		ft_get_outfile(t_list_token **pars);
int		ft_get_outfile_append(t_list_token **pars);
int		ft_open_failed(char *str);

//###########################################//
//		===== PARSING DIRECTORY =====
//###########################################//
//
//		----- Ft_Getword.c -----
char	*ft_getword_redirection(char **str, char c);
char	*ft_getword_space(char **str);
char	*ft_getword(char **str);
char	*ft_getword_quote(char **str, char c);

//		----- Ft_Join_Token.c -----
int		ft_join_token(t_list_token *lst);
int		ft_is_joinable(t_list_token *lst);
void	ft_strcat_join_token(char *s1, char *s2, int *i, int *j);
void	ft_free_and_get_new_word(t_list_token *lst, char *new_word);

//		----- Ft_Lenword.c -----
int		ft_lenword_redirection(char *str, char c);
int		ft_lenword_space(char *str);
int		ft_lenword(char *str);
int		ft_lenword_quote(char *str, char c);

//		----- Ft_Parse_Token.c -----
void	ft_parse_token(t_minishell *ms);
void	ft_print_error_parsing(int code_error);

//		----- Ft_parsing.c -----
void	ft_parsing(t_minishell *ms, char *str_prompt);
void	ft_print_list_token(t_list_token *token);

//		----- Ft_Redirection.c -----
int		ft_get_infile(t_list_token **pars);
int		ft_get_outfile(t_list_token **pars);

//		----- Ft_Token_Type.c -----
int		ft_is_redirection(char *str);
int		ft_which_redirection(char *str);
int		ft_is_builtins(char *str);
int		ft_is_pipe(char *str);
int		ft_is_space(char *str);

//		----- Ft_Tokenizing_Prompt.c -----
void	ft_tokenizing_prompt(t_minishell *ms, char *str);
char	*ft_get_token(char **str);
int		ft_get_token_type(char *str);
int		ft_token_is_quoted(char *str);

//		----- Ft_Trim_Quote -----
void	ft_trim_quote(t_minishell *ms);
char	*ft_remove_quote(char **str);
void	ft_strcat_trim_quote(char *s1, char *s2, size_t *i, size_t *j);

//###########################################//
//		===== HEREDOC DIRECTORY =====
//###########################################//
//
//		----- Ft_prompt.c.c -----
char	*ft_prompt(void);

//###########################################//
//		===== HEREDOC DIRECTORY =====
//###########################################//

//		----- Ft_heredoc.c -----
void	ft_heredoc(t_minishell *ms);
void	ft_heredoc_found(t_list_token **st, t_minishell *ms, int *i);
t_tok	*ft_get_heredoc(t_list_token *heredoc, t_minishell *ms, int i);
void	ft_eof_found(t_tok *heredoc, t_tok *new, char *name, t_minishell *ms);
void	ft_open_heredoc(t_list_token *heredoc, char *name, t_minishell *ms);

//		----- Ft_heredoc_utils.c -----
int		ft_syntax_heredoc(t_list_token *heredoc, t_minishell *ms);
void	ft_add_previous(t_list_token *st);
char	*ft_getname_heredoc(int nb);
char	*ft_getword_heredoc(char *word);
char	*ft_strjoin_heredoc(char *s1, char *s2);

//		----- Ft_heredoc_utils2.c -----
int		ft_strcmp_heredoc(t_list_token *heredoc, char *line);
void	ft_open_hd_two(char *all, t_minishell *ms, int fd_heredoc, t_tok *hd);
void	ft_free_init(t_list_venv *init);

//		----- Ft_error_heredoc.c -----
int		ft_error_eof_heredoc(char *str);
int		ft_error_heredoc(t_minishell *ms, int code_error);

//		----- Ft_Del_Heredoc.c -----
void	ft_del_heredoc(t_list_token *token);
void	ft_del_file(char *str);

//		----- Ft_Expand_heredoc.c -----
void	ft_replace_varenv_heredoc(char **str, t_minishell *ms);
void	ft_strcat_expand_heredoc(char *s1, char *s2, size_t *i, size_t *j);
void	ft_put_new_word_hd(char *var_env, char *new_word, size_t *i, size_t *j);
char	*ft_get_new_word_heredoc(char *w, char **var_env, size_t i);
int		ft_len_new_word_hd(char *w, char **var_env, int i);

//###########################################//
//		===== SIGNAL DIRECTORY ======
//###########################################//
//
//		----- Ft_handle_signals.c -----
void	ft_handle_signals_execution(int signo);
void	ft_handle_signals_prompt(int signo);

//		----- Ft_init_signals.c -----
void	ft_init_signals(void (*handle_signals)(int));

//###########################################//
//		===== SYNTAX DIRECTORY =====
//###########################################//
//
//		----- Ft_Pipe_Check.c -----
int		ft_pipe_check(t_list_token *syntax);
int		ft_pipe_error(t_list_token *syntax);

//		----- Ft_Quote_Closed.c -----
int		ft_quote_closed(char *str);
int		ft_quote_is_open(char *str, char c, size_t *i);

//		----- Ft_Redirection_Check.c -----
int		ft_redirection_check(t_list_token *syntax);

//		----- Ft_Syntax.c -----
int		ft_syntax(t_minishell *ms);
int		ft_check_syntax(t_list_token *syntax);
void	ft_display_error_syntax(int code_error);

//###########################################//
//		===== UTILS DIRECTORY =====
//###########################################//

//		----- Ft_Memory_Allocation.c -----
void	ft_freesplit(char **strs);

//		----- Ft_Utils_List.c -----
t_lcmd	*ft_lstnew_cmd(t_cmd *cmd);
t_tok	*ft_lstnew_token(char *word);
void	ft_lstadd_back_cmd(t_list_cmd **lst, t_list_cmd *nw);
void	ft_lstadd_back_token(t_list_token **lst, t_list_token *nw);

//		----- Utils.c -----
bool	ft_isspace(char c);
bool	ft_isspace_only(char *str);
void	swap_strings(char **a, char **b);

#endif
