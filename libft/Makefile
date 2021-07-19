# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 18:49:11 by aguerrer          #+#    #+#              #
#    Updated: 2021/07/18 20:24:07 by aguerrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra

SRC_DIR 	= srcs/
SRC_NAMES 	= ft_memset.c ft_bzero.c ft_strlen.c ft_strdup.c ft_strcmp.c \
			  ft_strnequ.c ft_array_swap.c ft_itoa.c ft_putchar.c ft_putstr.c \
			  ft_strnew.c ft_fopen.c ft_fclose.c ft_strncmp.c ft_putnbr.c \
			  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_memcpy.c \
			  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstcpy.c ft_lstappend.c

SRCS 		= $(addprefix $(SRC_DIR), $(SRC_NAMES))
OBJ_DIR 	= objs/
OBJ_NAMES 	= $(SRC_NAMES:.c=.o)
OBJS 		= $(addprefix $(OBJ_DIR), $(OBJ_NAMES))

HDR_NAMES 	= libft.h
HDR_DIR 	= includes/
HDRS 		= $(addprefix $(HDR_DIR),$(HDR_NAMES))

HDR_INC 	= $(addprefix -I./, $(HDR_DIR))

RED			= \033[0;31m
GREEN 		= \033[0;32m
NONE 		= \033[0m

all: $(NAME) $(HDRS)

$(NAME): $(OBJ_DIR) $(OBJS) $(HDRS)
	@ar rc $@ $(OBJS)
	@ranlib $@
	@echo "\t[ $(GREEN)✔$(NONE) ] libft/libft.a library"

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDRS)
	@$(CC) $(CFLAGS) $(HDR_INC) -c $< -o $@

clean:
	@rm -Rf $(OBJ_DIR)
	@echo "\t[ $(RED)✗$(NONE) ] libft/$(OBJ_DIR) directory"

fclean: clean
	@rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] libft/$(NAME) library"

re: fclean all

.PHONY: all clean fclean re project
