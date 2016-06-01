/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:46:33 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/01 18:30:46 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "queue.h"

/*
** bfs routine visits graph in breadthwards motion
**  - we stop if queue is empty (we have visited every node)
**  - if we get the end node, we add this way to anthill->way
**  - else, we visit this node (queue does not contain already visited node)
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
	free(node);
	my_dfs(anthill, upcoming, visited);
}

/*
** compute_way routine inits structure for breadth first search
*/

void		compute_way(t_anthill *anthill, char *start)
{
	t_queue			upcoming;
	t_set			visited;
	t_queue_node	*init;
	t_set			*way_init;

	queue_init(&upcoming);
	if (!set_init(visited, anthill->graph.nb_node / 2,
			ft_strcmp, hash_djb2))
		pexit("set_init: ");
	init = new_queue_node(start, NULL);
	queue_push(&upcoming, init);
	bfs(&upcoming, &visited, anthill);
	set_free(visited);
}
