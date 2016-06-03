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

static bool			get_cmd(char *str, char *pattern, char **pos)
{
	if (!ft_strncmp(*str, pattern))
	{
		ft_printf(VISU_START);
		return (false);
	}
	while (*str != ' ')
		str++;
	if (!graph_add_node(&(anthill->graph), str, ))
}

static enum e_line	process_node(t_anthill *anthill, char *str, strvect *vect)
{
	strvect_push(vect, ++str);

}

bool				set_graph_node_visu(char **str, t_anthill *anthill)
{
	char		*end;
	strvect		vect;
	enum e_line	line;

	while (**str)
	{
		end = end_line(*str);
		*end = '\0';
		line = type_of_line(*str);
		if (line == comment)
			line = process_node(anthill, *str);
		*end = '\n';
		if (line != comment)
			break ;
		*str = ++end;
	}
	if (!get_cmd(str, START_PATTERN_VISU, &anthill->start) ||
			!get_cmd(str, END_PATTERN_VISU, &anthill->end))
		return (false);
	return (true)
}
