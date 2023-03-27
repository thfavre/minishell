
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



# include "libft.h"
# include "struct.h"
# include "define.h"

//		===== ENVIRONMENT DIRECTORY =====
//
//		----- Ft_initenv.c -----
char	**ft_initenv(char **env);

//		----- Ft_setenv.c -----
int		ft_setenv(t_minishell *ms, char *key, char *value, int overwrite);

//		----- Ft_unsetenv.c -----
int		ft_unsetenv(char **env, char *key);

//		----- Ft_putenv.c -----
char	**ft_putenv(char **env, char *string);

//		----- Ft_getenv.c -----
char	*ft_getenv(char **env, char *key);

//		----- Ft_Get_Path.c -----
char	**ft_get_path(t_minishell *ms);
char	**ft_getsplitedpath(char **env);

//		===== CLOSE DIRECTORY =====
//
//		----- Ft_close.c -----
void	ft_close(t_minishell *ms);

//		----- Ft_Free_Allocation.c -----
void	*ft_free_env(char **env);
void	ft_free_path(t_minishell *ms);
void	ft_free_token(t_minishell *ms);
void	ft_free_pars(t_minishell *ms);

//		===== INIT_MINISHELL DIRECTORY =====
//
//		----- Ft_Init_Data.c -----
void	ft_init_minishell(t_minishell *ms, char **env);

//		----- Ft_Init_Cmd.c -----
t_cmd	*ft_init_cmd(t_list_token **pars, int *fd_pipe);

//		===== PARSING DIRECTORY =====
//
//		----- Ft_parsing.c -----
void	ft_parsing(t_minishell *ms, char *str_prompt);

//		----- Ft_Parse_Token.c -----
void	ft_parse_token(t_minishell *ms);

//		----- Ft_Redirection.c -----
int		ft_get_infile(t_list_token **pars);
int		ft_get_outfile(t_list_token **pars);

//		----- Ft_Getword.c -----
char	*ft_getword_redirection(char **str, char c);
char	*ft_getword_space(char **str);
char	*ft_getword(char **str);
void	ft_getword_in_quote(char **str, char *word, int *i, char c);

//		----- Ft_Lenword.c -----
int		ft_lenword_redirection(char *str, char c);
int		ft_lenword_space(char *str);
int		ft_lenword(char *str);

//		----- Ft_Token_Type.c -----
int		ft_is_redirection(char *str);
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

//		===== SIGNAL DIRECTORY ======
//
//		----- Ft_handle_signals.c -----
void	ft_handle_signals(int signo);

//		----- Ft_init_signals.c -----
void	ft_init_signals(void);

//		===== SYNTAX DIRECTORY =====
//
//		----- Ft_Check_Syntax.c -----
int		ft_check_syntax(t_minishell *ms);

//		===== EXECUTE DIRECTORY =====
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

//		===== BUILTINS DIRECTORY =====
//
//		----- Ft_env.c -----
int	ft_env(char **env);

//		----- Ft_pwd.c -----
int	ft_pwd(void);

//		----- Ft_cd.c -----
int	ft_cd(t_minishell *ms, char **paths);

//		----- Ft_unset.c -----
int	ft_unset(char **env, char **option);

//		----- Ft_echo.c -----
int	ft_echo(char **option);

//		----- Ft_exit.c -----
void	ft_exit(t_minishell *ms, char **option);

//		----- Ft_export.c -----
int	ft_export(t_minishell *ms, char **option);


//		===== UTILS DIRECTORY =====

//		----- Ft_Memory_Allocation.c -----
void	ft_freesplit(char **strs);


//		----- Ft_Utils_List.c -----
t_list_cmd		*ft_lstnew_cmd(t_cmd *cmd);
t_list_token	*ft_lstnew_token(char *word);
void			ft_lstadd_back_cmd(t_list_cmd **lst, t_list_cmd *nw);
void			ft_lstadd_back_token(t_list_token **lst, t_list_token *nw);

//		----- Utils.c -----
bool ft_isspace(char c);
bool ft_isspace_only(char *str);

//		===== VARIABLE_ENV DIRECTORY =====
//
//		----- Ft_Parse_Varenv.c -----
void	ft_parse_varenv(t_minishell *ms);
char	*ft_get_name_varenv(char *str);
int		ft_token_got_varenv(char *str);
int		ft_nbr_varenv(char *str);

//		----- Ft_Add_Varenv_In_Token.c -----
void	ft_add_varenv_in_token(t_list_token *token, char **env);

//		----- Ft_Replace_Varenv.c -----
void	ft_replace_varenv(t_list_token *token, char **env);
char	*ft_get_new_word(char *word, char **var_env);
int		ft_len_new_word(char *word, char **var_env);

#endif
