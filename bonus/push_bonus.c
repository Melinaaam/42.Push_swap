/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:44:53 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/27 15:26:44 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	push(t_pslist **a, t_pslist **b)
{
	t_pslist	*push_node;

	push_node = *a;
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (*b == NULL)
	{
		*b = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *b;
		push_node->next->prev = push_node;
		*b = push_node;
	}
}

void	ft_pa(t_pslist **a, t_pslist **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_pslist **a, t_pslist **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
