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

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = ft_printf\
	  strvect\
	  libft
LIB_DIR = $(addsuffix /, $(addprefix ./lib/, $(LIB)))
LIB_A = $(join $(LIB_DIR), $(addsuffix .a, $(LIB)))

NAME = lem_in

C_FILE = main.c\
		 set_anthill.c\
		 set_graph_node.c\
		 parse/skip_line.c\
		 debug/print_anthill.c

SRC_DIR = src

SRC = $(addprefix $(C_DIR)/, $(C_FILE))

INC = -I./inc\
	  -I./lib/inc

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(C_FILE:.c=.o))

all : $(NAME)

$(NAME) : $(LIB_A) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB_A)

$(LIB_A): lib/.git
	@echo 'build $(notdir $@)'
	@make -C $(dir $@)
	@make clean -C $(dir $@)

lib/.git:
	git submodule init
	git submodule update

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir obj obj/parse obj/debug

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

sw :
	rm -rf **/.*.sw[po]
	rm -rf **/.*.h.gch
	rm -rf ./inc/$(NAME).h.gch
