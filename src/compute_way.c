/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:46:33 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/01 10:59:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "queue.h"

/*
** bfs routine visits graph in breadthwards motion
**  - we stop if queue is empty (we have visited every node)
**  - if we get the end node, we add this way to anthill->way
**  - else, we visit this node (add its neighbour to visited and upcoming)
*/

static void	bfs(t_queue *upcoming, t_set *visited, t_anthill *anthill)
{
	t_queue_node	*node;

	if ((node = queue_pop(upcoming)) == NULL)
		return ;
	if (ft_strequ(node->id, anthill->end))
		add_way(anthill, node->way);
	else
		visit(node, upcoming, visited);
	my_dfs(anthill, upcoming, visited);
}

/*
** compute_way routine inits structure for breadth first search
*/

void		compute_way(t_anthill *anthill, char *start)
{
	t_queue		upcoming;
	t_set		visited;

	queue_init(&upcoming);
	if (!set_init(visited, anthill->graph.nb_node / 2,
			ft_strcmp, hash_djb2))
		pexit("set_init: ");
	queue_push(&upcoming, new_queue_node(start, NULL));
	bfs(&upcoming, &visited, anthill);
	set_free(visited);
}
