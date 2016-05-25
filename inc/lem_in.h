/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:30 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/25 11:52:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "hash_tables.h"

# include <stdint.h>

# define BUF_LEN 512
# define STOP "stop reading anthill description"
# define FORMAT "cannot accept line"
# define POS "this node is define twice with different position"
# define BEGINNING "this line should not begin with \'L\'"
# define START_CMD "too many start command"
# define END_CMD "too many end command"
# define PRINT_ERROR(TYPE, str) ft_printf("%s, %s:\n%s\n\n", STOP, TYPE, str)

# define GRAPH_GET_NODE(graph, id) (t_graph_node*)ht_get(&graph->ht, id)
# define KEY_VAL(id, node) (t_kv){id, ft_strlen(id), node, sizeof(t_graph_node)}
# define GRAPH_ADD(g, i, n) {t_kv = KEY_VAL(i, n); ht_put(g, &kv)}

typedef struct	s_graph_node
{
	char		**neighbour;
	int			pos_x;
	int			pos_y;
}				t_graph_node;

typedef struct	s_graph
{
	t_hash_tbl	ht;
	uint32_t	nb_node;
}				t_graph;

typedef struct	s_anthill
{
	uint32_t		nb_ant;
	char			*start;
	char			*end;
	t_graph			graph;
}				t_anthill;

/*
** this enum is used to parse stdin
*/

enum	e_line
{
	node,
	edge,
	comment,
	start_command,
	end_command,
	error
};

void	set_anthill(char *str, t_anthill *anthill);
bool	set_graph_node(char **str, t_anthill *anthill);

/*
** graph functions
*/

char		*graph_new_node(char *str, t_graph_node **new);
bool		graph_add_node(t_graph *graph, char *id, t_graph_node *new);

/*
** parse anthill
*/

char	*skip_line(char *str);
char	*end_line(char *str);

/*
** debug func
*/

void	print_anthill(t_anthill *anthill);

#endif
