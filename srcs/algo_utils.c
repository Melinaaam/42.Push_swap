/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:38:49 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/30 14:52:06 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	init_true_false_position(t_pslist	*list)
{
	int	i;
	int	mediane;

	i = 0;
	if (list == NULL)
		return ;
	mediane = size_list(list) / 2;
	while (list)
	{
		list->position = i;
		if (i <= mediane)
			list->mediane = true;
		else
		{
			list->mediane = false;
		}
		list = list->next;
		i++;
	}
	return ;
}

void	find_closer(t_pslist *a, t_pslist *b)
{
	t_pslist	*temp_a;
	long		landmark;

	if (b == NULL)
		return ;
	while (b)
	{
		landmark = LONG_MAX;
		temp_a = a;
		while (temp_a)
		{
			if (temp_a->nb > b->nb && temp_a->nb < landmark)
			{
				b->closer = temp_a;
				landmark = temp_a->nb;
			}
			temp_a = temp_a->next;
		}
		if (landmark == LONG_MAX)
		{
			b->closer = find_smallest(a);
		}
		b = b->next;
	}
	return ;
}

void	cost_calcul(t_pslist *a, t_pslist *b)
{
	int	len_lst_a;
	int	len_lst_b;
	int	i;

	if (b == NULL)
		return ;
	i = find_mediane(b, size_list(b));
	len_lst_a = size_list(a);
	len_lst_b = size_list(b);
	while (b)
	{
		if (b->mediane == true)
			b->cost = b->position;
		else
			b->cost = (len_lst_b - (b->position));
		if (b->closer->mediane == true)
			b->cost += b->closer->position;
		else
			b->cost += (len_lst_a - (b->closer->position));
		b = b->next;
	}
	return ;
}

void	find_cheapest_cost(t_pslist *b)
{
	t_pslist	*cheapest_node;
	long		i;

	if (b == NULL)
		return ;
	cheapest_node = NULL;
	i = LONG_MAX;
	while (b)
	{
		if (b->cost < i)
		{
			cheapest_node = b;
			i = b->cost;
		}
		b = b->next;
	}
	cheapest_node->min = true;
	return ;
}

void	move_to_a(t_pslist	**a, t_pslist **b)
{
	t_pslist	*move;

	move = *b;
	while (move)
	{
		if (move->min == true)
			break ;
		move = move->next;
	}
	if (move->mediane == true && move->closer->mediane == true)
	{
		while (move != *b && move->closer != *a)
			ft_rr(a, b);
		prepare_algo(*a, *b);
	}
	else if (!(move->mediane) && !(move->closer->mediane))
	{
		while (move != *b && move->closer != *a)
			ft_rrr(a, b);
		prepare_algo(*a, *b);
	}
	sort_a_and_b(a, b, move);
	ft_pa(a, b);
}
