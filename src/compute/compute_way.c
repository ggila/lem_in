/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:46:33 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/03 09:01:20 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "queue.h"

#include "ft_printf.h"
/*
** bfs routine visits graph in breadthwards motion
**  - we stop if queue is empty (we have visited every node)
**  - if we get the end node, we add this way to anthill->way
**  - else, we visit this node: we add its neighbour to queue upcoming if
**    they are not already visted and we mark them as visited
*/

static void			bfs(t_queue *upcoming, t_set *visited, t_anthill *anthill)
{
	t_qval	*node;

	ft_printf("\n\nvisited: ");
	set_print(visited, str_print);
	ft_printf("\n");
	if ((node = queue_pop(upcoming)) == NULL)
		return ;
	if (ft_strequ(node->node_id, anthill->end))
	{
		ft_printf("\nway: ", node->node_id);
		set_print(node->way, str_print);
//		add_way(anthill, node->way);
	}
	else
		visit(node, upcoming, visited, &anthill->graph);
	free(node);
	bfs(upcoming, visited, anthill);
}

/*
** init_bfs_routine set up:
**   - a queue 'upcoming' with one node containing graph start node id and an
**     empty way
**   - a set 'visited' to keep trace of graph node
*/

static void			init_bfs_struct(t_anthill *anthill, char *start,
									t_set *visited, t_queue *upcoming)
{
	t_qval	*init;

	if (!set_init(visited, anthill->graph.nb_node / 2,
			ft_strcmp, hash_djb2))
		pexit("set_init: ");
	set_put(visited, start);
	if (!(init = malloc(sizeof(t_queue_node))) ||
			!(init->way = malloc(sizeof(t_set))))
		pexit("malloc: ");
	set_init(init->way, anthill->graph.nb_node / 2, ft_strcmp, hash_djb2);
	init->node_id = start;
	queue_init(upcoming);
	queue_push(upcoming, init);
}

/*
** compute_way routine inits structure for breadth first search
*/

void				compute_way(t_anthill *anthill, char *start)
{
	t_queue			upcoming;
	t_set			visited;

	init_bfs_struct(anthill, start, &visited, &upcoming);
	bfs(&upcoming, &visited, anthill);
	ft_printf("\n");
	set_free(&visited);
}
