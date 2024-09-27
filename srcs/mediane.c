/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:39:11 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/27 23:36:49 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	partition_a(t_pslist **a, t_pslist **b)
{
	int	mediane;
	int size = size_list(*a);
	int	pushed;

	if (size <= 3)
		return (sort_three(a));
	mediane = find_mediane(*a, size_list(*a));
	pushed = 0;
	while (size)
	{
		if ((*a)->nb > mediane)
		{
			ft_pb(a, b);
			pushed++;
		}
		else
		{
			ft_ra(a);
		size--;
	}
	partition_a(a, b);
	partition_a(a, b);
}

void	move_to_top(t_pslist **a, int moves_to_top, int middle)
{
	if (moves_to_top != 0)
	{
		if (moves_to_top <= middle && moves_to_top > 0)
		{
			ft_ra(a);
			moves_to_top--;
		}
		while (moves_to_top > middle && moves_to_top < size_list(*a))
		{
			ft_rra(a);
			moves_to_top++;
		}
	}
}

int	find_mediane(t_pslist *a, int size_a)
{
	int	*tab;
	int	mediane;

	tab = NULL;
	create_tab(a, &tab, size_a);
	if (tab == NULL)
		exit(EXIT_FAILURE);
	sort_intab (&tab, size_a);
	mediane = tab[size_a / 2];
	free (tab);
	return (mediane);
}

int	pos_med(t_pslist *a, int mediane)
{
	int	pos;

	pos = 0;
	while (a->nb != mediane && a->next)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

int	find_position(t_pslist *a, int mediane, int pos_med)
{
	int			pos1;
	int			pos2;
	t_pslist	*last;

	if (a == NULL)
		return (-1);
	pos1 = 0;
	pos2 = size_list(a) - 1;
	while (a->nb > mediane && a->next && pos1 <= pos_med)
	{
		a = a->next;
		pos1++;
	}
	last = last_node(a);
	while (last->nb > mediane && last->prev && pos2 > pos_med)
	{
		last = last->prev;
		pos2--;
	}
	if (pos1 > pos2)
	{
		return (pos2);
	}
	return (pos1);
}
