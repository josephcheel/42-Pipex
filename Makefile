# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 12:21:20 by jcheel-n          #+#    #+#              #
#    Updated: 2022/09/13 12:23:57 by jcheel-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS =  -W -Wall -Wextra -Werror
XFLAGS	= -fsanitize=address -g2
AR		= ar -rcs
RM		= rm -f
MD		= mkdir -p
CP		= cp -f

MDT_DIR	= Mandatory/
SRC_DIR	= src/
INC_DIR	= inc/
OBJ_DIR	= obj/

INCLUDE = -I $(INC_DIR)

PPX_SRC	=	pipex.c errors.c commands.c \
		pipex_utils.c pipex_utils_2.c pipex_utils_3.c \
		script_arg.c ft_split_script.c ft_split_quotes.c \
		execution.c ignore_backslash.c

SRCS	+= $(addprefix $(MDT_DIR), $(addprefix $(SRC_DIR), $(PPX_SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: %.c Makefile
	@$(MD) $(dir $@)
	@echo "	Compiling: $<"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all: ${NAME}

${NAME}: $(OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) -o $(NAME)
	@echo "Pipex compiled."

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@${RM} ${NAME}

re: fclean all

norm: 
	norminette $(SRCS)

-include $(DEPS)

.PHONY: norm clean fclean re all
