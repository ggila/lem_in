/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graph_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:39:45 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 14:43:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "strvect.h"

static enum e_line	process_node(t_anthill *anthill,
						char *str, enum e_line p_line)
{
	t_graph_node	*new;
	char			*id;

	if ((id = graph_new_node(str, &new)) == NULL)
		return (error);
	if (p_line == start_command || p_line == end_command)
	{
		if (check_cmd(p_line == start_command ? &anthill->start :
					&anthill->end, p_line, id) == false)
			return (error);
	}
	if (graph_add_node(&(anthill->graph), id, new) == false)
		return (error);
	return (node);
}

bool				set_graph_node(char **str, t_anthill *anthill)
{
	enum e_line	previous_line;
	enum e_line	line;
	char		*end;

	while (**str)
	{
		end = end_line(*str);
		*end = '\0';
		line = type_of_line(*str);
		if (line == node)
			line = process_node(anthill, *str, previous_line);
		*end = '\n';
		if (line == edge)
			break ;
		previous_line = line;
		*str = ++end;
		if (line == error)
			return (false);
	}
	return (true);
}
