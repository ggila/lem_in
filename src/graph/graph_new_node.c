/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:16:58 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/29 19:45:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <stdio.h>

/*
** Set a new node from an input line (line = "id pos_x pos_y")
** return node id if everything is ok, else NULL
*/

static void	set(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ')
		i++;
	str[i] = '\0';
}

static void	set_pos(t_graph_node *new, char *str)
{
	new->pos_x = ft_atoi(str);
	while (*str != ' ')
		str++;
	str++;
	new->pos_y = ft_atoi(str);
}

char		*graph_new_node(char *str, t_graph_node **new)
{
	char			*id;
	int				len;

	set(str);
	if ((id = ft_strdup(str)) == NULL 
			|| (*new = malloc(sizeof(t_graph_node))) == NULL)
	{
		perror("graph_new_node: ");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(id);
	str[len] = ' ';
	set_pos(*new, str + len + 1);
	(*new)->neighbour = NULL;
	return (id);
}
