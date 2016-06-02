/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:10:49 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 14:47:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

bool			check_node(char *str)
{
	char *tmp;

	tmp = str;
	while (*tmp != ' ')
		tmp++;
	tmp++;
	while (*tmp)
	{
		if (*tmp != ' ' && (*tmp < '0' || *tmp > '9'))
		{
			PRINT_ERROR(POS_FORMAT, str);
			return (false);
		}
		tmp++;
	}
	tmp--;
	if (*tmp == ' ')
	{
		PRINT_ERROR(POS_MISSING, str);
		return (false);
	}
	return (true);
}
