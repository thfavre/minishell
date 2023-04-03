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
			  ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c ft_isnumber.c ft_str_isalnum.c\

SRCS_PATH	=
OBJS_PATH	=

SRCS_		:= $(addprefix $(SRCS_PATH), $(SRCS))
OBJS_		:= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

GREEN		= \033[1;32m
RESET		= \033[0m

CHARG_LINE_TXT	= echo "$(GREEN)██$(RESET)\c"

all:		${NAME}

${NAME}:	${OBJS_}
			@${LIB} ${NAME} ${OBJS_}
			@echo ""

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
					@${CC} ${FLAGS} -I ${INC} -c $< -o $@
					@$(CHARG_LINE_TXT)

clean:
			@${RM} ${OBJS_}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean flcean re
