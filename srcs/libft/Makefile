OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -Rf
LIB			= ar rc
INC			= includes
SRCS		= ft_isalnum.c ft_isprint.c ft_memcmp.c ft_memchr.c\
			  ft_strncmp.c ft_isalpha.c ft_toupper.c ft_isdigit.c \
			  ft_memcpy.c  ft_strchr.c ft_strlcpy.c ft_strlcat.c ft_calloc.c\
			  ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_atoi.c\
			  ft_memmove.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_memset.c\
			  ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c \
			  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
			  ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c ft_isnumber.c\

.c.o:		${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INC}

all:		${NAME}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

clean:
			@echo "LIBTF files suppressed"
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean flcean re

