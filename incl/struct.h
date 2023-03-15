
#ifndef STRUCT_H
# define STRUCT_H

//		### All Data ###

typedef struct s_minishell {
	char				**env;
	// char				**path;
	int					fd_pipe[2];
	int					fd_tmp_pipe;
	struct s_list_token	*token;
	struct s_list_cmd	*cmd;
}						t_minishell;

//		### Chain List Token ###

typedef struct s_list_token {
	char				*word;
	int					type;
	int					quote;
	struct s_list_token	*next;
}						t_list_token;

//		### Chain List Var_env ####

typedef struct s_list_venv {
	char	*word;
	struct s_list_venv	*next;
	struct s_list_venv	*previous;
}						t_list_venv;

//		### Chain List Cmd ###

typedef struct s_list_cmd {
	char				*cmd;
	char				**option;
	int					fd_read;
	int					fd_write;
	struct s_list_cmd	*next;
}						t_list_cmd;

typedef struct s_cmd {
	char	*cmd;
	char	**option;
	int		read;
	int		write;
}			t_cmd;

#endif
