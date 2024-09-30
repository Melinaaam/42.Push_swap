/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:54:03 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/28 17:07:16 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static	void	ft_swap(t_pslist **list)
{
	t_pslist	*first;
	t_pslist	*second;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*list = second;
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
