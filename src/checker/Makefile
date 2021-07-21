# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 22:10:51 by aguerrer          #+#    #+#              #
#    Updated: 2021/07/21 15:12:21 by aguerrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	checker
CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror
RM			=	rm -rf

GREEN 			= \033[0;32m
RED 			= \033[0;31m
NONE 			= \033[0m

DIR_HEADERS =	./includes/
DIR_SRCS	=	./srcs/
DIR_OBJS	=	./compiled_srcs/

SRC			=	checker.c init_stacks.c operations.c instructions.c utils.c	

SRCS		=	$(SRC)

OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)


all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)
				@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"
				@echo "\t[ $(GREEN)✔$(NONE) ] Executable '$(NAME)' created."

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				@mkdir $(DIR_OBJS)


clean:
				@$(RM) $(DIR_OBJS)
				@echo "\t[ $(RED)✗$(NONE) ] '"$(DIR_OBJS)"' has been deleted."

fclean:			clean
				@$(RM) $(NAME)
				@echo "\t[ $(RED)✗$(NONE) ] '"$(NAME)"' has been deleted."

re:				fclean all

.PHONY:			all clean fclean re
