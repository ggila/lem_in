/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:08:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/27 17:58:15 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	print_anthill(t_anthill *anthill)
{
	ft_printf("anthill:\n"
			"nb_ant: %d\n"
			"start: %s\n"
			"end: %s\n"
			"graph:\n", anthill->nb_ant,
			anthill->start ? anthill->start : "NULL",
			anthill->end ? anthill->end : "NULL");
	ht_print(&(anthill->graph.ht), str_print, graph_print_node);
	ft_printf("nb_node: %d\n", anthill->graph.nb_node);
}
