/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_queue_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:37:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/02 16:45:49 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_qval	*new_queue_node(char *id, t_set *way)
{
	t_qval	*new;

	if (!(new = malloc(sizeof(t_queue_node))))
		pexit("malloc: ");
	new->node_id = id;
	new->way = way;
	return (new);
}
