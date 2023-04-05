
	### COMPILATION ###

CC			= gcc -g3 -fsanitize=address
FLAGS		= -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= minishell
TEST		= minishell

	### PATH ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
INCS_PATH	= -Iincl

	### INCLUDE ###

GNL			= srcs/gnl
LIBFT		= srcs/libft

	### SOURCE FILE ###

MAIN_FILE		= main.c

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

	### OBJECTS ###

BUILT_FILES	:= $(addprefix $(OBJS_PATH)/builtins/, $(BUILT_FILES:.c=.o))
CLOSE_FILES	:= $(addprefix $(OBJS_PATH)/close/, $(CLOSE_FILES:.c=.o))
ENV_FILES	:= $(addprefix $(OBJS_PATH)/environment/, $(ENV_FILES:.c=.o))
EXEC_FILES	:= $(addprefix $(OBJS_PATH)/execute/, $(EXEC_FILES:.c=.o))
EXP_FILES	:= $(addprefix $(OBJS_PATH)/expand/, $(EXP_FILES:.c=.o))
INIT_FILES	:= $(addprefix $(OBJS_PATH)/init_minishell/, $(INIT_FILES:.c=.o))
LIBFT_FILES	:= $(addprefix $(OBJS_PATH)/libft/, $(LIBFT_FILES:.c=.o))
PARS_FILES	:= $(addprefix $(OBJS_PATH)/parsing/, $(PARS_FILES:.c=.o))
SIGN_FILES	:= $(addprefix $(OBJS_PATH)/signals/, $(SIGN_FILES:.c=.o))
STAX_FILES	:= $(addprefix $(OBJS_PATH)/syntax/, $(STAX_FILES:.c=.o))
UTILS_FILES	:= $(addprefix $(OBJS_PATH)/utils/, $(UTILS_FILES:.c=.o))
MAIN_FILE	:= $(addprefix $(OBJS_PATH)/, $(MAIN_FILE:.c=.o))

OBJS		:=  $(BUILT_FILES)\
				$(CLOSE_FILES)\
				$(ENV_FILES)\
				$(EXEC_FILES)\
				$(EXP_FILES)\
				$(INIT_FILES)\
				$(LIBFT_FILES)\
				$(PARS_FILES)\
				$(SIGN_FILES)\
				$(STAX_FILES)\
				$(UTILS_FILES)\
				$(MAIN_FILE)

	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
RESET		= \033[0m

	### TEXTES ###

LIBS_TXT		= echo "$(CYAN)=== Compiling LIBS ===$(RESET)"
LIBS_END_TXT	= echo "$(GREEN)=== LIBS Compilated ===$(RESET)"
START_TXT		= echo "$(CYAN)=== Compiling Project ===$(RESET)"
END_TXT			= echo "$(GREEN)=== Project Compilated ===$(RESET)"
CHARG_LINE_TXT	= echo "$(GREEN)██$(RESET)\c"
CLEAN_TXT		= echo "$(RED) Deleting all files$(RESET)"
FCLEAN_TXT		= echo "$(RED) Deleting $(NAME)$(RESET)"
NL_TXT			= echo ""

	### LIBS ###

LIBS		= -lreadline\
			  -lgnl\
			  -lft

	### LIBS PATH ###

ifdef READLINE
	LIBS_PATH	+= -L$(READLINE)/lib\
				   -L$(GNL)\
				   -L$(LIBFT)
	INCS_PATH	+= -I$(READLINE)/include
endif

	### RULES ###

all:		art tmp libs $(NAME)

art:
#			@tput setaf 2; cat .ascii_art/minishell; tput setaf default
			@tput setaf 2; cat .ascii_art/name; tput setaf default

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) -o $@ $(OBJS) $(LIBS_PATH) $(LIBS)
			@$(NL_TXT)
			@$(END_TXT)

tmp:
			@mkdir -p objs

libs:
			@$(LIBS_TXT)
			@make -sC $(GNL)
			@make -C $(LIBFT)
			@$(LIBS_END_TXT)
			@$(NL_TXT)
			@$(START_TXT)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					@mkdir -p $(@D)
					@$(CC) $(FLAGS) $(INCS_PATH) -c $< -o $@
					@$(CHARG_LINE_TXT)

clean:
			@$(CLEAN_TXT)
			@tput setaf 1; cat .ascii_art/trash; tput setaf default
			@make fclean -C $(GNL)
			@make fclean -C $(LIBFT)
			@rm -rf $(OBJS_PATH)

fclean:		clean
			@$(FCLEAN_TXT)
			@rm -rf $(NAME)
			@$(NL_TXT)

re:			fclean all

credit:
			@tput setaf 2; cat .ascii_art/name; tput setaf default

.PHONY:		clean fclean re tmp libs all credit
