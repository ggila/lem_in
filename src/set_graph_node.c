/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graph_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:39:45 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 22:03:15 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static enum e_line	type_of_line(char *str)
{
	enum e_line	line;

	if (*str == '#')
	{
		if (ft_strequ(str, "## Start"))
			line == start_command;
		else if (ft_strequ(str, "## End"))
			line == end_command;
	}
	else if (*str == 'L')
		error("wrong format");
	else if (ft_strcount(str, '-') == 1)
		line == edge;
	else if (ft_strcount(str, ' ') == 3)
		line == node;
	return (line);
}

void	process_node(t_anthill *anthill, char *str, enum e_line p_line)
{
	t_graph_node	*new;

	new = graph_new_node(str);
	graph_add_node(anthill, new);
	if (p_line == start_command)
	{
		if (anthill->start)
			error("more than one start command");
		anthill->start = new->id;
	}
	if (p_line == end_command)
	{
		if (anthill->end)
			error("more than one end command");
		anthill->end = new->id;
	}
}

void	set_graph_node(char **str, t_anthill *anthill)
{
	enum e_line	previous_line;
	enum e_line	line;
	char		*end;

	while (**str)
	{
		end = end_line(str);
		*end = '\0';
		line = type_of_line(*str);
		if (line == node)
			process_node(t_anthill, *str, previous_node);
		*end = '\n';
		if (line == edge)
			break;
		previous_line = line;
		*str = ++end;
	}
}
