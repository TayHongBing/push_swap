/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:32:25 by thong-bi          #+#    #+#             */
/*   Updated: 2023/05/19 17:25:08 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_nbr(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '+' || av[i] == '-') && av[i + 1] != '\0')
		i++;
	while (av[i] && (av[i] >= '0' && av[i] <= '9'))
		i++;
	if (av[i] != '\0' && !((av[i] >= '0' && av[i] <= '9')))
		return (0);
	return (1);
}

static int	nbr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while ((s1[i] && s2[j]) != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static int	is_0(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

static int	check_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(char **av)
{
	int	i;
	int	count_0;

	count_0 = 0;
	i = 1;
	while (av[i])
	{
		if (!is_nb(av[i]))
			return (0);
		count_0 += is_0(av[i]);
		i++;
	}
	if (count_0 > 1)
		return (0);
	if (check_dup(av))
		return (0);
	return (1);
}
