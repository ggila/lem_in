/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:10:14 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/27 18:14:15 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "strvect.h"
#include "ft_printf.h"

bool	check_cmd(char **pos, enum e_line cmd, char *id)
{
	t_strvect	vect;

	if (*pos && !ft_strequ(*pos, id))
	{
		strvect_init(&vect);
		if (strvect_push_str(&vect, *pos) == false
				|| strvect_push_str(&vect, " and ") == false
				|| strvect_push_str(&vect, id) == false)
			exit(EXIT_FAILURE);
		PRINT_ERROR(cmd == start_command ? START_CMD : END_CMD, vect.str);
		free(vect.str);
		return (false);
	}
	*pos = id;
	return (true);
}
