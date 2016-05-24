/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:16:58 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/24 18:02:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <stdio.h>

/*
** Set a new node from an input line (line = "id pos_x pos_y")
** return node id if everything is ok, else NULL
*/

static bool	check_line(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != ' ')
		tmp++;
	tmp++;
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	if (*tmp != ' ')
	{
		LINE_ERROR(str);
		return (false);
	}
	tmp++;
	while (*tmp && *tmp >= '0' && *tmp <= '9')
		tmp++;
	if (*tmp)
	{
		LINE_ERROR(str);
		return (false);
	}
	return (true);
}

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

	if (check_line(str) == false)
		return (NULL);
	set(str);
	if ((id = ft_strdup(str)) == NULL 
			|| (*new = malloc(sizeof(t_graph_node))) == NULL)
	{
		perror("graph_new_node: ");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(id);
	str[len] = ' ';
	set_pos(*new, str + 1);
	return (id);
}
