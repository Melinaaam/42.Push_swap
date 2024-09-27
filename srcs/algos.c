/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:22:28 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/27 14:51:07 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	prepare_algo(t_pslist *a, t_pslist *b)
{
	init_true_false_position(a);
	init_true_false_position(b);
	find_closer(a, b);
	cost_calcul(a, b);
	find_cheapest_cost(b);
}

void	sort_three(t_pslist **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->nb;
	second = (*a)->next->nb;
	third = (*a)->next->next->nb;
	if (first > second && second < third && first < third)
		ft_sa (a);
	else if (first > second && second < third && first > third)
		ft_ra (a);
	else if (first < second && second > third && first > third)
		ft_rra (a);
	else if (first > second && second > third && first > third)
	{
		ft_sa (a);
		ft_rra (a);
	}
	else if (first < second && second > third && first < third)
	{
		ft_sa (a);
		ft_ra (a);
	}
}

void	sort_a_and_b(t_pslist	**a, t_pslist **b, t_pslist *move)
{
	while (*b != move)
	{
		if (move->mediane == true)
			ft_rb(b);
		else
			ft_rrb(b);
	}
	while (*a != move->closer)
	{
		if (move->closer->mediane == true)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

void	algo(t_pslist **a, t_pslist **b)
{
	t_pslist	*smallest;

	while (size_list(*a) > 3)
		partition_a(a, b);
	sort_three(a);
	while (*b)
	{
		prepare_algo (*a, *b);
		move_to_a (a, b);
	}
	prepare_algo (*a, *b);
	smallest = find_smallest(*a);
	if (smallest->mediane == true)
		while (smallest != *a)
			ft_ra (a);
	else
		while (smallest != *a)
			ft_rra(a);
}
