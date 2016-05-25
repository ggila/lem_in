/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:08:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 21:11:49 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	print_anthill(t_anthill *anthill)
{
	ft_printf("atnhill:\n"
			"nb_ant: %d\n"
			"start: %s\n"
			"end: %s\n"
			"graph:\n\t", anthill->nb_ant, anthill->start, anthill->end);
	ht_print(anthill->graph.ht);
	ft_printf("nb_node:\n");
}
