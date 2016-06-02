/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_qval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 20:36:50 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/02 20:39:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	print_qva(t_qval *node)
{
	ft_printf("%s\t", node->node_id);
	set_print(node->way, str_print);
}
