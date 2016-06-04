/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 20:39:41 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/03 10:47:23 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static int	get_nb_ant(char *str)
{
	int	nb_ant;

	nb_ant = ft_atoi(str);
	if (nb_ant < 1)
	{
		ft_printf("Invalid number of ants\n");
		exit(EXIT_FAILURE);
	}
	return (nb_ant);
}

void		set_anthill(char *str, t_anthill *anthill, bool visual)
{
	anthill->nb_ant = get_nb_ant(str);
	str = skip_line(str);
	if (visual ? set_graph_node(&str, anthill) :
				set_graph_node_visual(&str, anthill))
	{
		if (!anthill->start || !anthill->end)
		{
			ft_printf("%s\n", anthill->start ? END_MISS: START_MISS);
			exit(EXIT_FAILURE);
		}
		set_graph_edge(&str, &anthill->graph, anthill->graph.nb_node);
	}
	print_anthill(anthill);
	ft_printf("%s", str);
}
