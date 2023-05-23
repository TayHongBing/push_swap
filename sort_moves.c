/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:36:52 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/24 00:03:05 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_move(t_list **list_a, t_list **list_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *list_a;
	tmp_b = *list_b;
	size_a = get_size(tmp_a);
	size_b = get_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->moves_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->moves_b = (size_b - tmp_b->pos) * -1;
		tmp_b->moves_a = tmp_b->target_p;
		if (tmp_b->target_p > size_a / 2)
			tmp_b->moves_a = (size_a - tmp_b->target_p) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_least_move(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	int		least;
	int		moves_a;
	int		moves_b;

	tmp = *list_b;
	least = INT_MAX;
	while (tmp)
	{
		if (abs_nbr(tmp->moves_a) + abs_nbr(tmp->moves_b) < abs_nbr(least))
		{
			least = abs_nbr(tmp->moves_a) + abs_nbr(tmp->moves_b);
			moves_a = tmp->moves_a;
			moves_b = tmp->moves_b;
		}
		tmp = tmp->next;
	}
	do_move(list_a, list_b, moves_a, moves_b);
}
