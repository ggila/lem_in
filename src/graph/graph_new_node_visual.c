/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:16:58 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 14:48:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <stdio.h>

/*
** malloc space for a new node from an input string str = "id"
** malloc space and duplicate string "id"
** return node id if everything is ok, else exit
*/

t_graph_node	*graph_new_node_visual(char *str)
{
	t_graph_node	*new;
	char			*id;

	if ((id = ft_strdup(str)) == NULL
			|| (new = malloc(sizeof(t_graph_node))) == NULL)
	{
		perror("graph_new_node: ");
		exit(EXIT_FAILURE);
	}
	new->neighbour = NULL;
	return (new);
}
