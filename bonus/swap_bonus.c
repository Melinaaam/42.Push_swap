/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:54:03 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/27 15:29:39 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static	void	ft_swap(t_pslist **list)
{
	*list = (*list)->next;
	(*list)->prev->prev = *list;
	(*list)->prev->next = (*list)->next;
	if ((*list)->next)
		(*list)->next->prev = (*list)->prev;
	(*list)->next = (*list)->prev;
	(*list)->prev = NULL;
}

void	ft_sa(t_pslist **a)
{
	ft_swap(a);
	ft_printf ("sa\n");
}

void	ft_sb(t_pslist **b)
{
	ft_swap(b);
	ft_printf ("sb\n");
}

void	ft_ss(t_pslist **a, t_pslist **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf ("ss\n");
}
