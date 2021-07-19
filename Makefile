# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 16:41:40 by aguerrer          #+#    #+#              #
#    Updated: 2021/07/19 19:07:59 by aguerrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER			= checker

CFLAGS			= -Wall -Wextra -Werror

PUSHSWAPFD 		= push_swap/

SRCSFD 			= src/
PUSHSWAP_SRC 	= main.c is_sorted.c quick_sort.c sort_3.c get_mediane.c \
			      reg_quick_sort.c follow_instructions.c fun_list.c \
			      get_opt.c get_stack.c instructions1.c instructions2.c \
			      instructions3.c print.c

OBJSFD 			= objs/
PUSHSWAP_OBJS 	= $(addprefix $(OBJSFD)$(PUSHSWAPFD), $(PUSHSWAP_SRC:.c=.o))

HDRSFD 			= includes/
HDRS 			= $(addprefix $(HDRSFD), $(HDR))

HDR_INC 		= -I./includes
LIBFT_HDR 		= -I./libft/includes/
LIB_BINARY 		= -L./libft -lft
LIBFT 			= libft/libft.a

RED 			= \033[0;31m
GREEN 			= \033[0;32m
NONE 			= \033[0m

all: check_libft project $(HDRS) $(NAME)
	@echo "Project ready"

bonus:
	@echo "Checking bonus..."
	@make -C $(SRCSFD)/$(CHECKER)
	@cp $(SRCSFD)/$(CHECKER)/$(CHECKER) .

check_libft:
	@echo "Checking libft..."
	@make -C libft

project:
	@echo "Checking project..."

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(PUSHSWAPFD): $(OBJSFD)
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(NAME): $(OBJSFD)$(PUSHSWAPFD) $(PUSHSWAP_OBJS) $(LIBFT) $(HDRS)
	@gcc $(CFLAGS) $(LIB_BINARY) $(PUSHSWAP_OBJS) -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

$(OBJSFD)$(PUSHSWAPFD)%.o: $(SRCSFD)$(PUSHSWAPFD)%.c $(HDRS) $(LIBFT)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
	@make -C ./libft clean
	@make -C ./src/checker clean
	@rm -rf checker

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
	@make -C ./libft fclean
	@make -C ./src/checker clean
	@rm -rf checker

re: fclean all

.PHONY: check_libft project all bonus clean fclean re
