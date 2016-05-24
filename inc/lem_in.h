/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:30 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/24 18:09:35 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "hash_tables.h"

# include <stdint.h>

# define BUF_LEN 512
# define ERR "stop reading anthill description, cannot accept line:\n%s\n\n"
# define LINE_ERROR(str) ft_printf(ERR, str)

# define GET_GRAPH_NODE(graph, id) (t_graph_node*)ht_get(graph, id)

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
bool		graph_add_node(t_anthill anthill, char *id, t_graph_node *new);

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
