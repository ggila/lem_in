/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:03:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/24 18:12:49 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	graph_add_node(t_anthill anthill, char *id, t_graph_node *new)
{
	t_graph_node	*node;

	if ((node = GET_GRAPH_NODE(anthill->graph, id)) != NULL)
		return (check_pos(node, new));
	anthill->graph.nb_node += 1;
	ht_putm();
}
