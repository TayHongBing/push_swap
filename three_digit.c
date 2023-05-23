/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:26:36 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/23 16:32:00 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	largest_index(t_list *list)
{
	int	idx;

	idx = list->index;
	while (list)
	{
		if (list->index > idx)
			idx = list->index;
		list = list->next;
	}
	return (idx);
}

void	three_digit(t_list **list)
{
	int	largest;

	if (is_sorted(*list))
		return ;
	largest = largest_index(*list);
	if ((*list)->index == largest)
		do_ra(list);
	else if ((*list)->next->index == largest)
		do_rra(list);
	if ((*list)->index > (*list)->next->index)
		do_sa(list);
}
