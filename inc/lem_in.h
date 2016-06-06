/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:30 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/03 15:44:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <ncurses.h>

# include "libft.h"
# include "hash_tables.h"
# include "set.h"
# include "queue.h"

# include <stdint.h>

# define BUF_LEN 512
# define START_PATTERN_VISU "##start "
# define END_PATTERN_VISU "##end "

# define NO_INPUT "empty input"
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
# define VISU_START "with -v, visual should be followed by start and end"
# define PRINT_ERROR(TYPE, str) ft_printf("%s, %s:\n%s\n\n", STOP, TYPE, str)

# define GRAPH_GET_NODE(graph, id) ((t_graph_node*)ht_get(&(graph)->ht, id))
# define GRAPH_GET_NEIGHBOUR(graph, id) (GRAPH_GET_NODE(graph, id)->neighbour)
# define KEY_VAL(id, node) (t_kv){id, ft_strlen(id), node, sizeof(t_graph_node)}

typedef struct	s_color
{
	char	fore;
	char	back;
}				t_color;

typedef struct	s_graph_node
{
	t_set		*neighbour;
	t_color		color;
	int			pos_x;
	int			pos_y;
}				t_graph_node;

typedef struct	s_graph
{
	t_hash_tbl	ht;
	uint32_t	nb_node;
}				t_graph;

/*
** s_qval is used in bfs queue to keep trace of the way that lead us to node_id
*/

typedef struct	s_qval
{
	char	*node_id;
	t_set	*way;
}				t_qval;

typedef struct	s_anthill
{
	char		*start;
	char		*end;
	uint32_t	nb_ant;
//	t_way		*ways;
	t_graph		graph;
}				t_anthill;

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

/*
** set anthill
*/

void			set_anthill(char *str, t_anthill *anthill, bool visu);
bool			set_graph_node(char **str, t_anthill *anthill);
bool			set_graph_node_visual(char **str, t_anthill *anthill);
void			set_graph_edge(char **str, t_graph *graph, uint32_t nb_node);

/*
** compute way
*/

void			compute_way(t_anthill *anthill, char *start);
void	visit(t_qval *q_node, t_queue *upcoming,
					t_set *visited, t_graph *graph);

/*
** graph functions
*/

char			*graph_new_node(char *str, t_graph_node **new);
t_graph_node	*graph_new_node_visual(char *str);
bool			graph_add_node(t_graph *graph, char *id, t_graph_node *new);
bool			graph_add_node_visual(t_graph *graph, char *id);
void			graph_add_edge(t_graph *graph, char *n1, char *n2,
								uint32_t size);

/*
** parse stdin
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
** misc
*/

void			pexit(char *str);
void			print_anthill(t_anthill *anthill);
void			graph_print_node(t_graph_node *node);
void			free_anthill(t_anthill *anthill);
t_qval			*new_queue_node(char *id, t_set *way);
void			print_qva(t_qval *node);

#endif
