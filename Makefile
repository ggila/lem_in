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
	  hash_tables\
	  set\
	  queue\
	  libft
LIB_DIR = $(addsuffix /, $(addprefix ./lib/, $(LIB)))
LIB_A = $(join $(LIB_DIR), $(addsuffix .a, $(LIB)))

NAME = lem_in

C_FILE = main.c\
		 set_anthill/set_anthill.c\
		 set_anthill/set_graph_node.c\
		 set_anthill/set_graph_edge.c\
		 compute/compute_way.c\
		 compute/visit.c\
		 set_anthill/parse/skip_line.c\
		 set_anthill/parse/type_of_line.c\
		 set_anthill/parse/check/check_pos.c\
		 set_anthill/parse/check/check_cmd.c\
		 set_anthill/parse/check/check_node.c\
		 set_anthill/parse/check/check_edge.c\
		 set_anthill/parse/check/check_hashtag.c\
		 graph/graph_new_node.c\
		 graph/graph_add_node.c\
		 graph/graph_add_edge.c\
		 graph/graph_print_node.c\
		 misc/pexit.c\
		 misc/free_anthill.c\
		 misc/print_anthill.c\
		 misc/new_queue_node.c

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
	@mkdir -p obj/set_anthill/parse/check\
				obj/misc\
				obj/graph\
				obj/compute

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
