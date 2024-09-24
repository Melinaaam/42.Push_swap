/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:22:28 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/24 15:02:23 by memotyle         ###   ########.fr       */
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
		insert_sort(a, b);
}

bool	list_sorted(t_pslist *a)
{
	if (a == NULL)
		return (true);
	while (a->next)
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

	while (size_list(*a) > 3)
		partition_a(a, b);
	sort_three(a);
	while(*b)
	{
		prepare_algo(*a, *b);
		move_to_a(a, b);
	}
	prepare_algo(*a, *b);
	smallest = find_smallest(*a);
	if (smallest->bellow_mediane == true)
		while(smallest != *a)
			ft_ra(a);
	else
		while (smallest != *a)
			ft_rra(a);
}
