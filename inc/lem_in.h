/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:30 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 22:07:39 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "hash_tables.h"

# include <stdint.h>

# define BUF_LEN 512

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
** parse anthill
*/

char	*skip_line(char *str);
char	*end_line(char *str);

/*
** debug func
*/

void	print_anthill(t_anthill *anthill);

#endif
