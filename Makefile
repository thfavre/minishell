# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 16:32:30 by mjulliat          #+#    #+#              #
#    Updated: 2023/02/20 11:15:44 by mjulliat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###

CC			= gcc -g3
FLAGS		= -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= minishell

	### PATH ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
INCS_PATH	= -Iincl
PRINTF_PATH	= ft_printf
LIBS_PATH	= -L$(PRINTF_PATH)

	### SOURCE FILE ###

SOURCES		= main.c

	# BUILTINS

BUILT_FILES	= ft_builtins.c

	# ENVIRONMENT

ENV_FILES	= ft_get_env.c\
			  ft_get_path.c

	# EXECUTION

EXEC_FILES	= ft_exec.c

	# INIT_DATA

INITD_FILES	= ft_init_data.c

	# PARSING

PARS_FILES	= ft_split_prompt.c\
			  ft_prompt.c\
			  ft_parsing.c

	# UTILS

UTILS_FILES	= utils.c\
			  ft_split.c\
			  ft_memory_allocation.c

	# ALL FILES

FILES		= $(SOURCES)\
			  $(BUILT_FILES)\
			  $(ENV_FILES)\
			  $(EXEC_FILES)\
			  $(INITD_FILES)\
			  $(UTILS_FILES)\
			  $(PARS_FILES)

	### OBJECTS ###

BUILT_FILES	:= $(addprefix builtins/, $(BUILT_FILES))
ENV_FILES	:= $(addprefix environment/, $(ENV_FILES))
EXEC_FILES	:= $(addprefix execution/, $(EXEC_FILES))
INITD_FILES := $(addprefix init_data/, $(INITD_FILES))
PARS_FILES	:= $(addprefix parsing/, $(PARS_FILES))
UTILS_FILES	:= $(addprefix utils/, $(UTILS_FILES))

SRCS		= $(addprefix $(SRCS_PATH)/, $(FILES))
OBJS		= $(addprefix $(OBJS_PATH)/, $(FILES:.c=.o))

	### LIBS ###

LIBS		= -lreadline -lftprintf

	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
NOC			= \033[0m
WHITE		= \033[1;37m

	### READLINE PATH ###

ifdef READLINE
	LIBS_PATH	+= -L$(READLINE)/lib
	INCS_PATH	+= -I$(READLINE)/include
endif

	### RULES ###

all:		printf tmp $(NAME)

$(NAME):	$(OBJS)
			@echo "$(BLUE)##### Compiling Project #####$(WHITE)"
			$(CC) $(FLAGS) $(LIBS_PATH) $(LIBS) -o $@ $^ 
			@echo "$(GREEN)##### Project Compilated #####$(WHITE)"

tmp:		
			@echo "$(CYAN)##### Compiling SRCS in OBJS #####$(WHITE)"
			@mkdir -p objs

printf:
			@echo "$(CYAN)##### Compilling FT_PRINTF #####$(WHITE)"
			make -sC $(PRINTF_PATH)
			cp ft_printf/libftprintf.a .
			@echo "$(GREEN)##### LIBFTPRINTF.A compilated #####$(WHITE)"

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					@mkdir -p $(@D)
					$(CC) $(FLAGS) $(INCS_PATH) -c $< -o $@

clean:	
			@echo "$(VIOLET)##### Supressing FILES #####$(YELLOW)"
			make fclean -C $(PRINTF_PATH)
			rm -rf $(OBJS_PATH)

fclean:		clean
			@echo "$(VIOLET)##### Supressing EXEC and LIBS #####$(YELLOW)"
			rm -rf libftprintf.a
			rm -rf $(NAME)

re:			fclean all

.PHONY:		clean, fclean, re, tmp, all, printf, minishell
