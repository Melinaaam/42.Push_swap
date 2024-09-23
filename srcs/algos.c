/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:22:28 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/23 14:33:23 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	choose_algo(t_pslist **a, t_pslist **b)
{
	int	size;

	size = size_list(*a);
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		ft_printf("more than 3 elements\n");
		//partition_a(a, b);
		insert_sort(a, b);
	}
}

bool	list_sorted(t_pslist *a)
{
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
		if (move->bellow_mediane == true)
			ft_rb(b);
		else
			ft_rrb(b);
	}
	while (*a != move->closer)
	{
		if(move->closer->bellow_mediane == true)
			ft_ra(a);
		else
			ft_rra(a);
	}
}
void	insert_sort(t_pslist **a, t_pslist **b)
{
	t_pslist	*smallest;
	int			len_a;

	len_a = size_list(*a);
	ft_printf("len_a = %d\n", len_a);
	while(len_a-- > 3)
		ft_pb(a, b);
	sort_three(a);

	ft_printf("list a after sort three\n");
	print_pslist(*a);
	ft_printf("list b after sort three\n");
	print_pslist(*b);

	while(*b)
	{
		prepare_algo(*a, *b);
		ft_printf("prepare_algo ok\n");
		move_to_a(a, b);
	}
	init_true_false_position(*a);
	smallest = find_smallest(*a);
	if (smallest->bellow_mediane == true)
		while(*a != smallest)
			ft_ra(a);
	else
		while (*a != smallest)
			ft_rra(a);
}
