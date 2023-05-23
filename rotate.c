/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:33:27 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/23 15:37:58 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*end;

	tmp = *list;
	*list = (*list)->next;
	end = get_list_bottom(*list);
	tmp->next = NULL;
	end->next = tmp;
}

void	do_ra(t_list **list_a)
{
	rotate(list_a);
	ft_putstr("ra\n");
}

void	do_rb(t_list **list_b)
{
	rotate(list_b);
	ft_putstr("rb\n");
}

void	do_rr(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_putstr("rr\n");
}
