/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/02 20:23:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "strvect.h"

#include <unistd.h>
#include <stdlib.h>

static void	init_anthill(t_anthill *anthill, uint32_t size_ht)
{
	anthill->nb_ant = 0;
	anthill->start = NULL;
	anthill->end = NULL;
//	anthill->ways = NULL;
	if (ht_init(&(anthill->graph.ht), size_ht, ft_strcmp, hash_djb2) == false)
		exit(EXIT_FAILURE);
	anthill->graph.nb_node = 0;
}

static char	*copy_stdin(void)
{
	t_strvect	vect;
	char		buf[BUF_LEN + 1];
	int			r;

	strvect_init(&vect);
	while ((r = read(0, buf, BUF_LEN)) > 0)
	{
		if (r == -1)
			pexit("read: ");
		buf[r] = '\0';
		if (strvect_push_str(&vect, buf) == false)
			pexit("strvect_push_str: ");
	}
	if (vect.size == 0)
	{
		ft_printf("%s\n", NO_INPUT);
		exit(EXIT_SUCCESS);
	}
	if (vect.str[vect.size - 1] != '\n' && strvect_push_char(&vect, '\n'))
		pexit("strvect_push_char: ");
	return (vect.str);
}

/*
** main routine:
**  - copy_stdin(): copy input, the project subject (lem_in.pdf) require it to
**    be printed back before exit on success
**  - set_anthill(): parse input into t_anthill
**  - compute_way(): check graph and find ways from start node to end node
**  - deplace_ants(): print ants deplacement
*/

int		main(void)
{
	t_anthill	anthill;
	char		*str;

	str = copy_stdin();
	init_anthill(&anthill, ft_strcount(str, '\n') / 4);
	set_anthill(str, &anthill);
	compute_way(&anthill, anthill.start);
	ft_printf("\ninput:\n%s", str);
	free(str);
	free_anthill(&anthill);
	return (EXIT_SUCCESS);
}
