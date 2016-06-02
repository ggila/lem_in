/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:09:41 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/27 18:14:21 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

bool	check_pos(t_graph_node *new, t_graph_node *node, char *id)
{
	if (new->pos_x != node->pos_x || new->pos_y != node->pos_y)
	{
		PRINT_ERROR(POS, id);
		return (false);
	}
	return (true);
}
