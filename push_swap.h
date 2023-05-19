/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:16:18 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/19 17:53:05 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_p;
	int				moves_a;
	int				moves_b;
	struct s_list	*next;
}	t_list;

int			check_input(char **av);
void		free_list(t_list **list);
void		error_quit(t_list **list_a, t_list **list_b);
void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
int			abs_nbr(int nbr);
