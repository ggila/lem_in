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
//# include "graph.h"

# define BUF_LEN 512


typedef struct	s_anthill
{
	int				nb_ant;
//	t_graph_node	*start;
//	t_graph_node	*end;
//	t_graph			*graph;
}				t_anthill;

enum	e_line
{
	start,
	end,
	comment,
	node,
	edge
};

void	set_anthill(char *str, t_anthill *anthill);

/*
** parse anthill
*/

char	*skip_line(char **str);

/*
** debug func
*/

void	print_anthill(t_anthill *anthill);

#endif
