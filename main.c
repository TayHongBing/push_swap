/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:24:47 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/22 18:18:20 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}
