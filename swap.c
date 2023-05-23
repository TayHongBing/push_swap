/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:09:40 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/23 15:18:00 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *list)
{
	int	tmp;

	if (list == NULL || list->next == NULL)
		return ;
	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
	tmp = list->index;
	list->index = list->next->index;
	list->next->index = tmp;
}

void	do_sa(t_list **list_a)
{
	swap(*list_a);
	ft_putstr("sa\n");
}

void	do_sb(t_list **list_b)
{
	swap(*list_b);
	ft_putstr("sb\n");
}

void	do_ss(t_list **list_a, t_list **list_b)
{
	swap(*list_a);
	swap(*list_b);
	ft_putstr("ss\n");
}
