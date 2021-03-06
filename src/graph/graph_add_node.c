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

bool	graph_add_node(t_graph *graph, char *id, t_graph_node *new)
{
	t_graph_node	*node;
	t_kv			kv;

	if ((node = GRAPH_GET_NODE(graph, id)) != NULL)
		return (check_pos(node, new, id));
	graph->nb_node += 1;
	kv = KEY_VAL(id, new);
	if (ht_put(&graph->ht, &kv) == false)
	{
		perror("graph_add_node :");
		exit(EXIT_FAILURE);
	}
	return (true);
}
