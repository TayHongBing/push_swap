/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:59:22 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/21 22:56:05 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int value)
{
	t_list	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_p = -1;
	new->moves_a = -1;
	new->moves_b = -1;
	new->next = NULL;
	return (new);
}

int	get_size(t_list *list)
{
	int	size;

	size = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

t_list	*get_list_bottom(t_list *list)
{
	while (list && list->next != NULL)
		list = list->next;
	return (list);
}

t_list	*get_list_second_last(t_list *list)
{
	while (list && list->next && list->next->next != NULL)
		list = list->next;
	return (list);
}

t_list	*list_add_bottom(t_list **list, t_list *new)
{
	t_list	*end;

	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	end = get_list_bottom(*list);
	end->next = new;
}
