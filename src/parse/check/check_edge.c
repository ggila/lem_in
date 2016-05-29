/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:10:49 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/29 22:26:59 by ggilaber         ###   ########.fr       */
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

static bool	check_edge_diff(char *n1, char *n2)
{
	if (ft_strequ(n1, n2))
	{
		PRINT_ERROR(EDGE_SAME, n1);
		return (false);
	}
	return (true);
}

bool		check_edge(char *str, t_graph *graph)
{
	char *tmp;

	tmp = str;
	if (!check_edge_pos(*str, '-', str))
		return (false);
	while (*tmp != '-')
		tmp++;
	if (!check_edge_pos(*(tmp + 1), '\0', str))
		return (false);
	*tmp = '\0';
	if (!check_edge_node(&graph->ht, str)
			|| !check_edge_node(&graph->ht, tmp + 1)
			|| !check_edge_diff(str, tmp + 1))
	{
		*tmp = '-';
		return (false);
	}
	*tmp = '-';
	return true;
}
