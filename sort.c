/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:49:13 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/24 00:37:17 by thong-bi         ###   ########.fr       */
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

static void	shift_list(t_list **list)
{
	int	lowest_p;
	int	list_size;

	list_size = get_size(*list);
	lowest_p = lowest_idx_pos(*list);
	if (lowest_p > list_size / 2)
	{
		while (lowest_p < list_size)
		{
			do_rra(list);
			lowest_p++;
		}
	}
	else
	{
		while (lowest_p > 0)
		{
			do_ra(list);
			lowest_p--;
		}
	}
}

void	sort(t_list **list_a, t_list **list_b)
{
	save_three(list_a, list_b);
	three_digit(list_a);
	while (*list_b)
	{
		get_target_p(list_a, list_b);
		get_move(list_a, list_b);
		do_least_move(list_a, list_b);
	}
	if (!is_sorted(*list_a))
		shift_list(list_a);
}
