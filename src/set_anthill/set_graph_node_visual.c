/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graph_node_visu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 10:47:47 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/03 16:31:58 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "strvect.h"
#include "ft_printf.h"

static enum e_line	process_line(t_anthill *anthill, char *str)
{
	char	*end_node;

	while (*str)
	{
		while (*str && !ft_isalnum(*str))
			str++;
		end_node = str;
		while (*end_node && ft_isalnum(*str))
			end_node++;
		if (end_node == '\0')
			return error;
		end_node = '\0';
		if (!graph_add_node_visual(&anthill->graph, str))
			return error;
		str = end_node;
		*str = ' ';
		str++;
	}
	return (comment);
}

bool				set_graph_node_visual(char **str, t_anthill *anthill)
{
	enum e_line	line;
	char		*end;
//	strvect		vect;

	line = comment;
	while (**str)
	{
		end = end_line(*str);
		*end = '\0';
		if (**str == '#')
			line = process_line(anthill, *str + 1);
		*end = '\n';
		if (line == error)
			return (false);
		if (**str != '#')
			break ;
		*str = ++end;
	}
	return (true);
}
