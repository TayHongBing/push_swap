/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:52:56 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/22 18:17:59 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_values(int ac, char **av)
{
	t_list		*list_a;
	long int	nbr;
	int			i;

	list_a = NULL;
	nbr = 0;
	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_quit(&list_a, NULL);
		if (i == 1)
			list_a = new_node((int)nbr);
		else
			list_add_bottom(&list_a, new_node((int)nbr));
		i++;
	}
	return (list_a);
}

void	assign_index(t_list *list)
{
	t_list	*tmp;
	t_list	*hold;
	int		value;

	hold = list;
	while (list)
	{
		tmp = hold;
		value = 1;
		while (tmp)
		{
			if (list->value > tmp->value)
				value++;
			tmp = tmp->next;
		}
		list->index = value;
		list = list->next;
	}
}
