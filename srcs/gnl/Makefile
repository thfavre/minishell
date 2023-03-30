OBJS		= ${SRCS:.c=.o}
NAME		= libgnl.a
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -Rf
LIB			= ar rc
INC			= includes
SRCS		= get_next_line.c\
			  get_next_line_utils.c

.c.o:		${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INC}

all:		${NAME}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

clean:
			@echo "GNL files suppressed"
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean flcean re

