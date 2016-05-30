/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 19:48:33 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 14:49:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static void	add_neighbour(t_set **set, char *str, uint32_t size)
{
	if (!(*set))
	{
		if ((*set = malloc(sizeof(t_set))) == NULL ||
				!set_init(*set, size, ft_strcmp, hash_djb2))
			pexit();
	}
	if (!set_putm(*set, str, ft_strlen(str)))
		pexit();
}

void		graph_add_edge(t_graph *graph, char *n1, char *n2, uint32_t size)
{
	t_graph_node	*node;

	node = GRAPH_GET_NODE(graph, n1);
	add_neighbour(&node->neighbour, n2, size);
	node = GRAPH_GET_NODE(graph, n2);
	add_neighbour(&node->neighbour, n1, size);
}
