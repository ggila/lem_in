/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:30 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/31 11:31:35 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "hash_tables.h"
# include "set.h"

# include <stdint.h>

# define BUF_LEN 512

# define STOP "stop reading anthill description"
# define FORMAT "cannot accept line"
# define POS "this node is define twice with different position"
# define BEGINNING "this line should not begin with \'L\'"
# define START_CMD "too many start command"
# define START_MISS "missing start node"
# define END_CMD "too many end command"
# define END_MISS "missing end node"
# define POS_FORMAT "bad format position for this node"
# define POS_MISSING "missing position for this node"
# define EDGE_MISSING "missing a node for this edge"
# define EDGE_UNKNOWN "unknown node used in edge"
# define EDGE_SAME "this node has a self-connection"
# define UNEXPECTED "unexpected line in edge description"

# define PRINT_ERROR(TYPE, str) ft_printf("%s, %s:\n%s\n\n", STOP, TYPE, str)

# define GRAPH_GET_NODE(graph, id) ((t_graph_node*)ht_get(&(graph)->ht, id))
# define GRAPH_GET_NEIGHBOUR(graph, id) (GRAPH_GET_NODE(graph, id)->neighbour)
# define KEY_VAL(id, node) (t_kv){id, ft_strlen(id), node, sizeof(t_graph_node)}

typedef struct	s_graph_node
{
	t_set		*neighbour;
	int			pos_x;
	int			pos_y;
}				t_graph_node;

typedef struct	s_graph
{
	t_hash_tbl	ht;
	uint32_t	nb_node;
}				t_graph;

typedef struct	s_way
{
	t_set			node;
	t_set			path;
	uint32_t		lenght;
	struct s_way	*subpath;
	struct s_way	*next;
}				t_way;

typedef struct	s_anthill
{
	uint32_t	nb_ant;
	char		*start;
	char		*end;
	t_way		*ways;
	t_graph		graph;
}				t_anthill;

typedef struct	s_queue_node
{
	char	*id;
	t_path	path;
}				t_queue_node;

/*
** this enum is used to parse stdin
*/

enum			e_line
{
	node,
	edge,
	comment,
	start_command,
	end_command,
	error
};

void			pexit(void);
void			set_anthill(char *str, t_anthill *anthill);
bool			set_graph_node(char **str, t_anthill *anthill);
void			set_graph_edge(char **str, t_graph *graph, uint32_t nb_node);
void			compute_way(t_anthill *anthill, char *start);
void			free_anthill(t_anthill *anthill);

/*
** graph functions
*/

char			*graph_new_node(char *str, t_graph_node **new);
bool			graph_add_node(t_graph *graph, char *id, t_graph_node *new);
void			graph_add_edge(t_graph *graph, char *n1, char *n2,
								uint32_t size);

/*
** parse anthill
*/

char			*skip_line(char *str);
char			*end_line(char *str);
bool			check_pos(t_graph_node *new, t_graph_node *node, char *id);
bool			check_cmd(char **pos, enum e_line cmd, char *id);
bool			check_node(char *str);
bool			check_edge(char *str, t_graph *graph);
enum e_line		check_hashtag(char *str);
enum e_line		type_of_line(char *str);

/*
** debug func
*/

void			print_anthill(t_anthill *anthill);
void			graph_print_node(t_graph_node *node);

#endif
