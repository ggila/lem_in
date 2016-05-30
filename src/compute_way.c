/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:46:33 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 18:44:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "queue.h"

static void	my_dfs(t_way *way, t_queue *upcoming, t_hash_tbl *visited, char *id)
{
	(void)this;
	(void)other;
	(void)visited;
	(void)id;
}

void	compute_way(t_anthill *anthill)
{
	t_hash_tbl	visited;
	t_queue		upcoming;
	t_way		*way;

	queue_init(queue);
	if (!ht_init(&visited, 2 * anthill->graph.nb_node,
			ft_strcmp, hash_djb2))
		pexit();
	my_dfs();
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
