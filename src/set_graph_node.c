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

uint32_t	count_line_len(char *str)
{
	while (*str && *str != '\n')
		i++;
}

enum e_line	next_line(char *str)
{
	enum e_line	line;
	int len;

	len = count_line_len(str)
	if (*str == '#')
		line = check_comment(str);
	return (line);
}

void	set_graph_node(char **str, t_anthill *anthill)
{
	while (*str && next_line(*str) != edge)
		(void)anthill;
}
