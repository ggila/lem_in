# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 08:45:05 by ggilaber          #+#    #+#              #
#*   Updated: 2015/04/05 08:04:28 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_GREY =		\033[1;37m

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = ft_printf\
	  strvect\
	  libft
LIB_DIR = $(addsuffix /, $(addprefix ./lib/, $(LIB)))
LIB_A = $(join $(LIB_DIR), $(addsuffix .a, $(LIB)))

NAME = lem_in

C_FILE = main.c

SRC_DIR = src

SRC = $(addprefix $(C_DIR)/, $(C_FILE))

INC = -I./inc\
	  -I./lib/inc

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(C_FILE:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ) $(LIB_A)
	$(CC) $(FLAGS) -o $(NAME) $(LIB_A) $(OBJ)

$(LIB_A): lib/.git
	@echo 'build $(notdir $@)'
	@make -C $(dir $@)
	@make clean -C $(dir $@)

lib/.git:
	git submdodule init
	git submdodule update

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir obj

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

sw :
	rm -rf **/.*.sw[po]
	rm -rf **/.*.h.gch
	rm -rf ./inc/$(NAME).h.gch
