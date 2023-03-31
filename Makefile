
	### COMPILATION ###

CC			= gcc -g3 -fsanitize=address
FLAGS		= -Wall -Werror -Wextra
ECHO		= @echo 

	### EXECUTABLE ###

NAME		= minishell

	### PATH ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
INCS_PATH	= -Iincl

	### INCLUDE ###

GNL			= srcs/gnl
LIBFT		= srcs/libft

	### SOURCE FILE ###

SOURCES		= main.c

	# BUILTINS

BUILT_FILES	= ft_cd.c\
			  ft_env.c\
			  ft_pwd.c\
			  ft_echo.c\
			  ft_unset.c\
			  ft_exit.c\
			  ft_export.c

	# CLOSE

CLOSE_FILES	= ft_close.c\
			  ft_free_allocation.c

	# ENVIRONMENT

ENV_FILES	= ft_initenv.c\
			  ft_setenv.c\
			  ft_getenv.c\
			  ft_unsetenv.c\
			  ft_getsplitedpath.c

	# EXECUTE

EXEC_FILES	= ft_execute.c\
			  ft_execute_cmds.c\
			  ft_execute_cmd.c\
			  ft_execute_builtin.c\
			  ft_execute_external.c

	# EXPAND

EXP_FILES	= ft_expand.c\
			  ft_replace_varenv.c\
			  ft_add_varenv_in_token.c\
			  ft_expand_utils.c

	# INIT_MINISHELL

INIT_FILES	= ft_init_minishell.c\
			  ft_init_cmd.c\
			  ft_redirection.c

	# PARSING

PARS_FILES	= ft_getword.c\
			  ft_lenword.c\
			  ft_heredoc.c\
			  ft_parse_token.c\
			  ft_parsing.c\
			  ft_token_type.c\
			  ft_tokenizing_prompt.c\
			  ft_trim_quote.c\
			  ft_join_token.c

	# SIGNALS

SIGN_FILES	= ft_init_signals.c\
			  ft_handle_signals.c

	# SYNTAX

STAX_FILES	= ft_syntax.c\
			  ft_pipe_check.c\
			  ft_quote_closed.c\
			  ft_redirection_check.c

	# UTILS

UTILS_FILES	= ft_memory_allocation.c\
			  ft_utils_list.c\
			  utils.c

	# ALL FILES

FILES		= $(SOURCES)\
			  $(BUILT_FILES)\
			  $(CLOSE_FILES)\
			  $(ENV_FILES)\
			  $(EXEC_FILES)\
			  $(EXP_FILES)\
			  $(INIT_FILES)\
			  $(LIBFT_FILES)\
			  $(PARS_FILES)\
			  $(SIGN_FILES)\
			  $(STAX_FILES)\
			  $(UTILS_FILES)

	### OBJECTS ###

BUILT_FILES	:= $(addprefix builtins/, $(BUILT_FILES))
CLOSE_FILES	:= $(addprefix close/, $(CLOSE_FILES))
ENV_FILES	:= $(addprefix environment/, $(ENV_FILES))
EXEC_FILES	:= $(addprefix execute/, $(EXEC_FILES))
EXP_FILES	:= $(addprefix expand/, $(EXP_FILES))
INIT_FILES	:= $(addprefix init_minishell/, $(INIT_FILES))
LIBFT_FILES	:= $(addprefix libft/, $(LIBFT_FILES))
PARS_FILES	:= $(addprefix parsing/, $(PARS_FILES))
SIGN_FILES	:= $(addprefix signals/, $(SIGN_FILES))
STAX_FILES	:= $(addprefix syntax/, $(STAX_FILES))
UTILS_FILES	:= $(addprefix utils/, $(UTILS_FILES))

SRCS		= $(addprefix $(SRCS_PATH)/, $(FILES))
OBJS		= $(addprefix $(OBJS_PATH)/, $(FILES:.c=.o))

	### LIBS ###

LIBS		= -lreadline\
			  -lgnl\
			  -lft

	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
NOC			= \033[0m
WHITE		= \033[1;37m
RESET		= \033[0m

	### READLINE PATH ###

ifdef READLINE
	LIBS_PATH	+= -L$(READLINE)/lib\
				   -L$(GNL)\
				   -L$(LIBFT)
	INCS_PATH	+= -I$(READLINE)/include
endif

	### RULES ###

all:		tmp libs $(NAME)

$(NAME):	$(OBJS)
			@echo "$(CYAN)##### Compiling Project #####$(RESET)"
			@$(CC) $(FLAGS) -o $@ $^ $(LIBS_PATH) $(LIBS)
			@echo "$(GREEN)##### Project Compilated #####$(RESET)"

tmp:
			@mkdir -p objs

libs:
			@echo "$(CYAN)##### Compiling LIBS #####$(WHITE)"
			@make -sC $(GNL)
			@make -sC $(LIBFT)
			@echo "$(CYAN)##### Compiling SRCS in OBJS #####$(RESET)"

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					@mkdir -p $(@D)
					@$(CC) $(FLAGS) $(INCS_PATH) -c $< -o $@

clean:
			@echo "$(VIOLET)##### Supressing FILES #####$(YELLOW)"
			@make fclean -C $(GNL)
			@make fclean -C $(LIBFT)
			rm -rf $(OBJS_PATH)
			$(ECHO) "$(WHITE)"

fclean:		clean
			@echo "$(VIOLET)##### Supressing EXEC #####$(YELLOW)"
			rm -rf $(NAME)
			$(ECHO) "$(RESET)"

re:			fclean all

.PHONY:		clean, fclean, re, tmp, libs all, minishell
