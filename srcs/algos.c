/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:22:28 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/21 19:23:54 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	stack_sorted(t_pslist *a)
{
	// ft_printf("stack_sorted ok\n");
	// print_pslist(a);

	if (a == NULL)
		return (true);

	while (a && a->next)
	{
		if (a->nb > a->next->nb)
			return (false);
		a = a->next;
	}
	return (true);
}

void	sort_three(t_pslist **a)
{
	int	first;
	int	second;
	int	third;

	// if (is_sorted(*a))
	// 	return ;

	// ft_printf("sort_three OK\n");

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

void	sort_five(t_pslist **a, t_pslist **b)
{
	//ft_printf("debut du tri avec sort_five\n");
	print_pslist(*a);

	int	size;
	int	smallest;

	size = size_stack(*a);

	//ft_printf("size a :[%d] \n", size);

	smallest = ft_smallest(*a);

	//ft_printf("smallest : [%d]\n", smallest);

	if (size != 4 &&size != 5)
		return ;
	if (size == 5)
	{
		move_smallest(a);
		ft_pb(a, b);
		smallest = ft_smallest(*a);
		move_smallest(a);
		ft_pb(a, b);
		sort_three(a);
		ft_pa(a, b);
		ft_pa(a, b);
	}
	else if (size == 4)
	{
		smallest = ft_smallest(*a);
		move_smallest(a);
		ft_pb(a, b);
		sort_three(a);
		ft_pa(a, b);
	}
	//ft_printf("Apres le tri dans sort_five\n");
	//print_pslist(*a);
}

void	push_biggest_in_a(t_pslist **b, t_pslist **a)
{
	int	cost;
	int	mediane;

	cost = position_biggest(*b, find_biggest(*b));
	mediane = pos_med(*b, find_mediane(*b, size_stack(*b)));
	ft_printf("mediane : [%d]\n", mediane);
	ft_printf("cost : [%d]\n", cost);
	while (cost && a)
	{
		if (cost >= mediane)
		{
			ft_rb(b);
			cost--;
		}
		else if (cost < mediane)
			ft_rrb(b);
		ft_pa(a, b);
		ft_printf("cost : [%d]\n", cost);
	}
	ft_pa(a, b);
}
