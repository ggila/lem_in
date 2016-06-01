/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:46:33 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/31 11:32:27 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "queue.h"

/*
** bfs routine:
**  - we stop if queue is empty (we have visited every node) or if we have
**    find the end node
*/

static void	bfs(t_queue *upcoming, t_set *visited, t_anthill *anthill)
{
	t_queue_node	*node;

	if ((node = queue_pop(upcoming)) == NULL)
		return ;
	if (ft_strequ(node->id, anthill->end))
		add_way(anthill, node->way);
	else if (!set_isin(visited, node->id))
		visit(node, upcoming, visited);
	my_dfs(anthill, upcoming, visited);
}

/*
** compute_way routine:
**  - we get all nodes neighbours of start, because one and only one ant can stand
**    in an anthill node (other than start and end node), only those nodes can lead
**    to acceptble way from start to end.
**  - for each of those nodes:
**      - a breadth first search is compute (see upper explanation)
**      - if end node is reach, we need to check if it's an acceptable way
**        (see explanation) 
*/

void	compute_way(t_anthill *anthill, char *start)
{
	t_queue		upcoming;
	t_set		visited;

	queue_init(&upcoming);
	if (!set_init(visited, anthill->graph.nb_node / 2,
			ft_strcmp, hash_djb2))
		pexit();
	queue_push(&upcoming, new_queue_node(start, NULL));
	bfs(&upcoming, &visited, anthill);
	free_datastruct(&visited);
}
