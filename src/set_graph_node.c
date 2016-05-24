/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graph_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:39:45 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/24 18:06:21 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static enum e_line	check_hashtag(char *str)
{
	enum e_line	line;

	if (ft_strequ(str, "## Start"))
		line = start_command;
	else if (ft_strequ(str, "## End"))
		line = end_command;
	else
		line = comment;
	return line;
}

static enum e_line	type_of_line(char *str)
{
	enum e_line	line;

	if (*str == '#')
		line = check_hashtag(str);
	else if (*str == 'L')
	{
		LINE_ERROR(str);
		return (error);
	}
	else if (ft_strcount(str, '-') == 1)
		line = edge;
	else if (ft_strcount(str, ' ') == 2)
		line = node;
	else
	{
		LINE_ERROR(str);
		return (error);
	}
	return (line);
}

bool	check_cmd(char **pos, enum e_line cmd, char *id)
{
	if (*pos)
	{
		ft_printf("stop reading anthill description: too many %s cmd",
					cmd == start_command ? "start" : "end");
		return (false);
	}
	*pos = id;
	return (true);
}

// free id

enum e_line	process_node(t_anthill *anthill, char *str, enum e_line p_line)
{
	t_graph_node	*new;
	char			*id;

	id = graph_new_node(str, &new);
	if ((id = graph_new_node(str, &new)) == NULL
			|| graph_add_node(anthill, id, new) == false)
		return (error);
	if (p_line == start_command || p_line == end_command)
	{
		if (check_cmd(&anthill->start, p_line, id) == false)
			return (error);
	}
	return (node);
}

bool	set_graph_node(char **str, t_anthill *anthill)
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
			break;
		if (line == error)
			return (false);
		previous_line = line;
		*str = ++end;
	}
	return (true);
}
