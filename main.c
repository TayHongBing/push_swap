/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:24:47 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/24 00:19:42 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

static void	push_swap(t_list **list_a, t_list **list_b, int list_size)
{
	if (list_size == 2 && !is_sorted(*list_a))
		do_sa(list_a);
	else if (list_size == 3)
		three_digit(list_a);
	else if (list_size > 3 && !is_sorted(*list_a))
		sort(list_a, list_b);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	int		list_size;

	if (ac < 2)
		return (NULL);
	if (!check_input(av))
		error_quit(NULL, NULL);
	list_a = fill_values(ac, av);
	list_b = NULL;
	list_size = get_size(list_a);
	assign_index(list_a);
	push_swap(&list_a, &list_b, list_size);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
