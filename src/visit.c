/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:15:32 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/01 17:36:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "queue.h"

/*
**
**    typedef struct   s_queue_node
**    {
**        char    *node_id;
**        t_set   *way;
**    }                t_queue_node;
**
*/

static void	add_neighbour(char *id, t_set *way, t_queue *queue)
{
	t_set			*new_way;
	t_queue_node	*new_q_node;

	new_way = queue->tail ? way : set_copy(way)
	new_q_node = new_queue_node(id, new_way);
	queue_push(&queue, new_q_node);
}

void	visit(t_queue_node *q_node, t_queue *upcoming, t_hash_tbl *visited)
{
	t_set	*neighbours;
	t_queue	new_upcoming;
	char	*id;

	neighbour = GRAPH_GET_NEIGHBOUR(q_node->node_id);
	while (id = set_getnextelem(neighbour))
	{
		if (!set_isin(visited, neihgbour))
			add_id(id, q_node->way, &new_upcoming);
	}
	update_way(&new_upcoming);
	queue_push_queue(upcoming, &new_upcoming);
}

