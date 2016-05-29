/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hashtag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:11:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/27 18:14:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

enum e_line	check_hashtag(char *str)
{
	enum e_line	line;

	if (ft_strequ(str, "##start"))
		line = start_command;
	else if (ft_strequ(str, "##end"))
		line = end_command;
	else
		line = comment;
	return line;
}
