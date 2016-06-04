/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:03:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/27 18:10:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <stdio.h>

bool	graph_add_node_visual(t_graph *graph, char *id)
{
	t_graph_node	*new;
	t_kv			kv;

	if (GRAPH_GET_NODE(graph, id))
		return (error);
	new = graph_new_node_visual(id);
	graph->nb_node += 1;
	kv = KEY_VAL(id, new);
	if (ht_put(&graph->ht, &kv) == false)
	{
		perror("ht_put :");
		exit(EXIT_FAILURE);
	}
	return (true);
}
