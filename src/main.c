/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 21:21:25 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "strvect.h"

#include <unistd.h>
#include <stdlib.h>

char	*copy_stdin(void)
{
	t_strvect	vect;
	char		buf[BUF_LEN + 1];
	int			r;

	strvect_init(&vect);
	while ((r = read(0, buf, BUF_LEN)) > 0)
	{
		if (r == -1)
			exit(EXIT_FAILURE);
		buf[r] = '\0';
		if (strvect_push_str(&vect, buf) == false)
			exit(EXIT_FAILURE);
	}
	return (vect.str);
}

int	main(void)
{
	t_anthill	anthill;
	char		*str;

	str = copy_stdin();
	set_anthill(str, &anthill);
//	compute_anthill(av[1]);
	ft_printf("\n%s", str);
	free(str);
//	free_anthill(anthill);
	return (EXIT_SUCCESS);
}
