/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:43:38 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/23 22:16:42 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_position(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	lowest_idx_pos(t_list *list)
{
	int	ret;
	int	lowest;

	assign_position(list);
	lowest = list->index;
	while (list)
	{
		if (list->index <= lowest)
		{
			lowest = list->index;
			ret = list->pos;
		}
		list = list->next;
	}
	return (ret);
}

static int	get_target(t_list *list_a, int b_idx)
{
	t_list	*tmp_a;
	int		target_p;
	int		target_i;

	target_i = INT_MAX;
	tmp_a = list_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_i)
		{
			target_i = tmp_a->index;
			target_p = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_i != INT_MAX)
		return (target_p);
	return (lowest_idx_pos(list_a));
}

void	get_target_p(t_list **list_a, t_list **list_b)
{
	t_list	*tmp_b;

	tmp_b = *list_b;
	assign_position(list_a);
	assign_position(list_b);
	while (tmp_b)
	{
		tmp_b->target_p = get_target(*list_a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}
