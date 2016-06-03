/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graph_node_visu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 10:47:47 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/03 11:10:36 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static bool			get_cmd(char **str, char **pos)
{
}

static enum e_line	process_node(t_anthill *anthill, char *str, strvect *vect)
{

}

bool	set_graph_node_visu(char **str, t_anthill *anthill)
{
	strvect		vect;
	enum e_line	line;

	if (!get_cmd(str, "##start ", &anthill->start) ||
			!get_cmd(str, "##end ", &anthill->end))
	{
		ft_printf(MISS_VISU_START);
		return (false);
	}
	while (**str)
	{
		end = end_line(*str);
		*end = '\0';
		line = type_of_line(*str);
		if (line == node)
			line = process_node(anthill, *str);
		*end = '\n';
		if (line != comment)
			break ;
		*str = ++end;
	}
	return (true)
}
