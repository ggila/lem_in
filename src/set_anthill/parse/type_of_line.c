/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 17:59:45 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/29 22:04:19 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

enum e_line	type_of_line(char *str)
{
	enum e_line	line;

	if (*str == '#')
		line = check_hashtag(str);
	else if (*str == 'L')
	{
		PRINT_ERROR(BEGINNING, str);
		return (error);
	}
	else if (ft_strcount(str, '-') == 1)
		line = edge;
	else if (ft_strcount(str, ' ') == 2)
		line = check_node(str) ? node : error;
	else
	{
		PRINT_ERROR(FORMAT, str);
		return (error);
	}
	return (line);
}
