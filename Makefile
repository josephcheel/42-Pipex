NAME = pipex

SRCS = $(shell ls Mandatory/*.c)#pipex.c errors.c commands.c pipex_utils.c pipex_utils_2.c pipex_utils_3.c script_arg.c ft_split_script.c ft_split_quotes.c execution.c ignore_backslash.c is_file_extension.c
OBJS = ${SRCS:.c=.o}
HEADER = Mandatory/pipex.h
CC = gcc
CFLAGS =  -g -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}

${NAME}: ${SRCS} $(HEADER) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

norm: 
	norminette $(SRCS)
.PHONY: clean fclean re all
