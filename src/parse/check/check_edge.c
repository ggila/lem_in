/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:10:49 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/29 19:03:16 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static bool	check_edge_pos(char c, char unwanted, char *str)
{
	if (c == unwanted)
	{
		PRINT_ERROR(EDGE_MISSING, str);
		return false;
	}
	return true;
}

static bool	check_edge_node(t_hash_tbl *ht, char *str)
{
	if (!ht_isset(ht, str))
	{
		PRINT_ERROR(EDGE_UNKNOWN, str);
		return (false);
	}
	return (true);
}

bool		check_edge(char *str, t_graph *graph)
{
	char *tmp;

	tmp = str;
	check_edge_pos(*str, '-', str);
	while (*tmp != '-')
		tmp++;
	check_edge_pos(*(tmp + 1), '\0', str);
	*tmp = '\0';
	if (!check_edge_node(&graph->ht, str)
			|| !check_edge_node(&graph->ht, tmp + 1))
		return (false);
	*tmp = '-';
	return true;
}
