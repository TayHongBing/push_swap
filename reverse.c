/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:41:56 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/23 15:59:30 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_list **list)
{
	t_list	*end;
	t_list	*before_end;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	before_end = *list;
	while (before_end->next->next != NULL)
		before_end = before_end->next;
	end = before_end->next;
	before_end->next = NULL;
	end->next = *list;
	*list = end;
}

void	do_rra(t_list **list_a)
{
	rev_rotate(list_a);
	ft_putstr("rra\n");
}

void	do_rra(t_list **list_b)
{
	rev_rotate(list_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_list **list_a, t_list **list_b)
{
	rev_rotate(list_a);
	rev_rotate(list_b);
	ft_putstr("rrr\n");
}
