/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graph_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 17:55:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 14:42:46 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static void			process_edge(t_graph *graph, char *str, uint32_t size)
{
	char *tmp;

	tmp = str;
	while (*tmp != '-')
		tmp++;
	*tmp = '\0';
	graph_add_edge(graph, str, tmp + 1, size);
	*tmp = '-';
}

static enum e_line	process_line(t_graph *graph, enum e_line line,
									char *str, uint32_t size)
{
	if (line == edge)
	{
		if (!check_edge(str, graph))
			return (error);
		process_edge(graph, str, size);
	}
	else if (line == node || line == start_command ||
				line == start_command)
	{
		PRINT_ERROR(UNEXPECTED, str);
		return (error);
	}
	return (line);
}

void				set_graph_edge(char **str, t_graph *graph,
									uint32_t nb_node)
{
	enum e_line	line;
	char		*end;

	while (**str)
	{
		end = end_line(*str);
		*end = '\0';
		line = type_of_line(*str);
		process_line(graph, line, *str, nb_node);
		*end = '\n';
		if (line == error)
			return ;
		*str = ++end;
	}
	return ;
}
