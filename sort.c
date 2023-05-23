/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:49:13 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/23 21:36:59 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	save_three(t_list **list_a, t_list **list_b)
{
	int	list_size;
	int	pushed;
	int	i;

	list_size = get_size(*list_a);
	pushed = 0;
	i = 0;
	while (list_size > 6 && i < list_size && pushed < list_size / 2)
	{
		if ((*list_a)->index <= list_size / 2)
		{
			do_pb(list_a, list_b);
			pushed++;
		}
		else
			do_ra(list_a);
		i++;
	}
	while (list_size - pushed > 3)
	{
		do_pb(list_a, list_b);
		pushed++;
	}
}

void	sort(t_list **list_a, t_list **list_b)
{
	save_three(list_a, list_b);
	three_digit(list_a);
	while (*list_b)
	{

	}
}
