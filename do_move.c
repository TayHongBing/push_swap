/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:03:23 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/24 00:16:13 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_reverse_both(t_list **a, t_list **b, int *moves_a, int *moves_b)
{
	while (*moves_a < 0 && *moves_b < 0)
	{
		*moves_a++;
		*moves_b++;
		do_rrr(a, b);
	}
}

static void	do_rotate_both(t_list **a, t_list **b, int *moves_a, int *moves_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		*moves_a--;
		*moves_b--;
		do_rr(a, b);
	}
}

static void	do_rotate_a(t_list **a, int *moves)
{
	while (*moves)
	{
		if (*moves > 0)
		{
			do_ra(a);
			*moves--;
		}
		else if (*moves < 0)
		{
			do_rra(a);
			*moves++;
		}
	}
}

static void	do_rotate_b(t_list **b, int *moves)
{
	while (*moves)
	{
		if (*moves > 0)
		{
			do_rb(b);
			*moves--;
		}
		else if (*moves < 0)
		{
			do_rrb(b);
			*moves++;
		}
	}
}

void	do_move(t_list **list_a, t_list **list_b, int moves_a, int moves_b)
{
	if (moves_a < 0 && moves_b < 0)
		do_reverse_both(list_a, list_b, &moves_a, &moves_b);
	else if (moves_a > 0 && moves_b > 0)
		do_rotate_both(list_a, list_b, &moves_a, &moves_b);
	do_rotate_a(list_a, &moves_a);
	do_rotate_b(list_b, &moves_b);
	do_pa(list_a, list_b);
}
