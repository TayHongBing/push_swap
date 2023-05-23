/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:16:18 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/24 00:31:28 by thong-bi         ###   ########.fr       */
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
int			is_sorted(t_list *list);
t_list		*new_node(int value);
int			get_size(t_list *list);
t_list		*get_list_bottom(t_list *list);
t_list		*get_list_second_last(t_list *list);
void		list_add_bottom(t_list **list, t_list *new);
void		do_pa(t_list **list_a, t_list **list_b);
void		do_pb(t_list **list_a, t_list **list_b);
void		do_ra(t_list **list_a);
void		do_rb(t_list **list_b);
void		do_rr(t_list **list_a, t_list **list_b);
void		do_rra(t_list **list_a);
void		do_rrb(t_list **list_b);
void		do_rrr(t_list **list_a, t_list **list_b);
void		do_sa(t_list **list_a);
void		do_sb(t_list **list_b);
void		do_ss(t_list **list_a, t_list **list_b);
void		three_digit(t_list **list);
void		get_target_p(t_list **list_a, t_list **list_b);
int			lowest_idx_pos(t_list *list);
void		get_move(t_list **list_a, t_list **list_b);
void		do_move(t_list **list_a, t_list **list_b, int moves_a, int moves_b);
void		do_least_move(t_list **list_a, t_list **list_b);
void		sort(t_list **list_a, t_list **list_b);
t_list		*fill_values(int ac, char **av);
void		assign_index(t_list *list);

#endif
