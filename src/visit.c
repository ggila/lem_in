/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:15:32 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/01 12:11:35 by ggilaber         ###   ########.fr       */
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

void	add_neighbour()
{
	node_neighbour = set_getnextelem(neighbours);
	new = new_queue_node();
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
			add_id(neihgbour, &new_upcoming);
	}
	update_way(&new_upcoming);
	queue_push_queue(upcoming, &new_upcoming);
}

