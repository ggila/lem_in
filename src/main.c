/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 18:51:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "strvect.h"

#include <unistd.h>

char	*copy_stdin(void)
{
	t_strvect	vect;
	char		buf[BUF_LEN + 1];
	int			r;

		ft_printf("a\n");
	while ((r = read(0, buf, BUF_LEN)) > 0)
	{
		ft_printf("b\n");
		if (r == -1)
			return NULL;
		buf[r] = '\0';
		if (strvect_push_str(&vect, buf) == false)
			return NULL;
		ft_printf("c\n");
	}
	return (vect.str);
}

int	main(void)
{
//	t_anthill	anthill;
	char		*str;

	if ((str = copy_stdin()) == NULL)
		return (EXIT_FAILURE);
	ft_printf("%s", str);
//	set_anthill(str, &anthill);
//	compute_anthill(av[1]);
	free(str);
//	free_anthill(anthill);
	return (EXIT_SUCCESS);
}
