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
#include "ft_printf.h"
#include "queue.h"

static void	visit(t_queue_node *node, t_queue *upcoming, t_hash_tbl *visited)
{
	i = 0;
	while ((id = set_getnextelem(init)))
	{
		if (!set_init(&((way_init + i)->node), 2 * anthill->graph.nb_node,
						ft_strcmp, hash_djb2))
			pexit();
		my_dfs(way_init + i, way_init, &visited, id);
		i++;
	}
}

static void	my_dfs(t_anthill *anthill, t_queue *upcoming, t_hash_tbl *visited)
{
	t_queue_node	*node;

	if ((node = queue_pop(upcoming)) == NULL)
		return ;
	if (ft_strequ(node->id, anthill->start) && node->path)
		free_way(node->path);
	else if (ft_strequ(node->id, anthill->end))
		add_way(&anthill->ways, node->way);
	else
		visit(node, upcoming, visited);
	my_dfs(anthill, upcoming, visited);
}

static void	init_visited(char *start, t_graph *graph, t_hash_tbl *visited)
{
	if (!ht_init(visited, anthill->graph.nb_node / 2,
			ft_strcmp, hash_djb2))
		pexit();
}

void	compute_way(t_anthill *anthill, char *start)
{
	t_hash_tbl	visited;
	t_queue		upcoming;
	t_way		*way_init;
	t_set		*neighbour_init;

	neighbour_init = GRAPH_GET_NEIGHBOUR(start);
	init_upcoming(&upcoming, neighbour_init);
	init_
	init_visited(anthill->start, &anthill->graph, &visited);
	my_dfs(NULL, &upcoming, &visited, id);
}
