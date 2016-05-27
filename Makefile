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
	  libft\
	  hash_tables
LIB_DIR = $(addsuffix /, $(addprefix ./lib/, $(LIB)))
LIB_A = $(join $(LIB_DIR), $(addsuffix .a, $(LIB)))

NAME = lem_in

C_FILE = main.c\
		 error.c\
		 set_anthill.c\
		 set_graph_node.c\
		 parse/skip_line.c\
		 parse/check/check_pos.c\
		 parse/check/check_cmd.c\
		 parse/check/check_node.c\
		 parse/check/check_hashtag.c\
		 graph/graph_new_node.c\
		 graph/graph_add_node.c\
		 graph/graph_print_node.c\
		 debug/print_anthill.c\

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
	@mkdir obj obj/parse obj/debug obj/graph

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@for l in $(LIB_DIR); do make -C $$l fclean; done
	@rm -rf $(NAME)

re : fclean all

sw :
	rm -rf **/.*.sw[po]
	rm -rf **/.*.h.gch
	rm -rf ./inc/$(NAME).h.gch
