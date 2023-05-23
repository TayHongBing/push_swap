/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:00:30 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/23 16:09:46 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_list **list_a, t_list **list_b)
{
	push(list_b, list_a);
	ft_putstr("pa\n");
}

void	do_pb(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	ft_putstr("pb\n");
}
