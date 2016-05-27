/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_print_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:45:42 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/27 15:45:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	graph_print_node(t_graph_node *node)
{
	ft_printf("(%d, %d)", node->pos_x, node->pos_y);
//	ht_print(node->neighbour);
}
