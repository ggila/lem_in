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
#include "ft_printf.h"

static enum e_line	process_line(t_anthill *anthill, char *str, strvect *vect)
{
	char	*end_node;

	while (*str)
	{
		while (*str && !ft_isalphanum(*str))
			str++;
		end_node = str;
		while (*end_node && ft_islphanum(*str))
			end_node++;
		if (end_node == '\0')
			return error;
		end_node = '\0';
		if (!graph_add_node_visu(str, anthill))
			return error;
		str = end_node;
		*str = ' ';
		str++;
	}
}

bool				set_graph_node_visu(char **str, t_anthill *anthill)
{
	enum e_line	line;
	char		*end;
	strvect		vect;

	line = comment;
	while (**str)
	{
		end = end_line(*str);
		*end = '\0';
		if (**str == '#')
			line = process_node(anthill, *str + 1);
		*end = '\n';
		if (line == error)
			return (false);
		if (**str != '#')
			break ;
		*str = ++end;
	}
	return (true)
}
