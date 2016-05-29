/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:08:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/29 20:12:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	print_graph(t_graph *graph)
{
	ht_print(&(graph->ht), str_print, graph_print_node);
	ft_printf("nb_node: %d\n", graph->nb_node);
}

void	print_anthill(t_anthill *anthill)
{
	ft_printf("anthill:\n"
			"nb_ant: %d\n"
			"start: %s\n"
			"end: %s\n"
			"graph:\n", anthill->nb_ant,
			anthill->start ? anthill->start : "NULL",
			anthill->end ? anthill->end : "NULL");
	print_graph(&anthill->graph);
}
