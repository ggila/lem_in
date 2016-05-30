/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 15:46:16 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "strvect.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	init_anthill(t_anthill *anthill, uint32_t size_ht)
{
	anthill->start = NULL;
	anthill->end = NULL;
	if (ht_init(&(anthill->graph.ht), size_ht, ft_strcmp, hash_djb2) == false)
		exit(EXIT_FAILURE);
	anthill->graph.nb_node = 0;
}

char	*copy_stdin(void)
{
	t_strvect	vect;
	char		buf[BUF_LEN + 1];
	int			r;

	strvect_init(&vect);
	while ((r = read(0, buf, BUF_LEN)) > 0)
	{
		if (r == -1)
		{
			perror("copy_stdin: ");
			exit(EXIT_FAILURE);
		}
		buf[r] = '\0';
		if (strvect_push_str(&vect, buf) == false)
			exit(EXIT_FAILURE);
	}
	if (vect.str[vect.size - 1] != '\n')
	{
		ft_printf("\'\\n\' please\n");
		exit(EXIT_FAILURE);
	}
	return (vect.str);
}

int		main(void)
{
	t_anthill	anthill;
	char		*str;

	str = copy_stdin();
	init_anthill(&anthill, ft_strcount(str, '\n'));
	set_anthill(str, &anthill);
	compute_way(&anthill);
	ft_printf("\n%s", str);
	free(str);
	free_anthill(&anthill);
	return (EXIT_SUCCESS);
}
