# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 16:32:30 by mjulliat          #+#    #+#              #
#    Updated: 2023/02/27 13:36:37 by thfavre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###

CC			= gcc -g3
FLAGS		= # -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= minishell

	### PATH ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
INCS_PATH	= -Iincl

	### SOURCE FILE ###

SOURCES		= main.c


FILES		= $(SOURCES)

	### OBJECTS ###

SRCS		= $(addprefix $(SRCS_PATH)/, $(FILES))
OBJS		= $(addprefix $(OBJS_PATH)/, $(FILES:.c=.o))

	### LIBS ###

LIBS		= -lreadline

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

all:		tmp $(NAME)

$(NAME):	$(OBJS)
			@echo "$(BLUE)##### Compiling Project #####$(WHITE)"
			$(CC) $(FLAGS) $(LIBS_PATH) $(LIBS) -o $@ $^
			@echo "$(GREEN)##### Project Compilated #####$(WHITE)"

tmp:
			@echo "$(CYAN)##### Compiling SRCS in OBJS #####$(WHITE)"
			@mkdir -p objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					@mkdir -p $(@D)
					$(CC) $(FLAGS) $(INCS_PATH) -c $< -o $@

clean:
			@echo "$(VIOLET)##### Supressing FILES #####$(YELLOW)"
			rm -rf $(OBJS_PATH)

fclean:		clean
			@echo "$(VIOLET)##### Supressing EXEC and LIBS #####$(YELLOW)"
			rm -rf $(NAME)

re:			fclean all

.PHONY:		clean, fclean, re, tmp, all, minishell
