/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:15:32 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/03 09:11:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "ft_printf.h"
static void	update_way(t_qval *node)
{
	set_put(node->way, node->node_id);
}

static void	add_id(char *id, t_set *way, t_queue *queue)
{
	t_set	*new_way;
	t_qval	*new_q_node;

	new_way = queue->tail ? way : set_copy(way);
	new_q_node = new_queue_node(id, new_way);
	queue_push(queue, new_q_node);
}

void	visit(t_qval *q_node, t_queue *upcoming,
					t_set *visited, t_graph *graph)
{
	t_set		*neighbours;
	t_set_it	it;
	t_queue		new_upcoming;
	char		*id;
	bool		flag;

	flag = false;
	queue_init(&new_upcoming);
	set_it_init(&it);
	neighbours = GRAPH_GET_NEIGHBOUR(graph, q_node->node_id);
//	set_print(neighbours, str_print);
	ft_printf("\nvisit: %s\t", q_node->node_id);
	while ((id = set_getnextelem(neighbours, &it)))
	{
//		ft_printf("\n%s\t", id);
		if (!set_isin(visited, id))
		{
			ft_printf("%s ", id);
			if (!ft_strequ(id, "g"))
			set_put(visited, id);
			add_id(id, q_node->way, &new_upcoming);
			flag = true;
		}
	}
	if (flag)
	{
		queue_map(&new_upcoming, update_way);
		queue_push_queue(upcoming, &new_upcoming);
	}
	else
		set_free(q_node->way);
}
