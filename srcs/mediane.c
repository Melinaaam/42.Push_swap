/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:39:11 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 09:40:06 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	partition_a(t_pslist **a, t_pslist **b)
{
	int	mediane;
	int	middle_list;
	int	moves_to_top;

	mediane = find_mediane(*a, size_list(*a));
	middle_list = size_list(*a) / 2;
	moves_to_top = find_position(*a, mediane, pos_med(*a, mediane));
	while (middle_list > 0 && size_list(*a) > 3)
	{
		move_to_top(a, moves_to_top, middle_list);
		ft_pb(a, b);
		mediane = find_mediane(*a, size_list(*a));
		moves_to_top = find_position(*a, mediane, pos_med(*a, mediane));
		middle_list--;
	}
}

void	move_to_top(t_pslist **a, int moves_to_top, int middle)
{
	if (moves_to_top != 0)
	{
		if (moves_to_top <= middle && moves_to_top > 0)
		{
			ft_ra (a);
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
