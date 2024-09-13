/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:44:53 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/13 18:43:22 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_pa(t_pslist **a, t_pslist **b)
{
	t_pslist	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_printf ("pa\n");
}

void	ft_pb(t_pslist **a, t_pslist **b)
{
	t_pslist	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_printf ("pb\n");
}

void	ft_sa(t_pslist **a)
{
	t_pslist	*temp;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	ft_printf ("sa\n");
}

void	ft_sb(t_pslist **b)
{
	t_pslist	*temp;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	ft_printf ("sb\n");
}

void	ft_ss(t_pslist **a, t_pslist **b)
{
	ft_sa(a);
	ft_sb(b);
	ft_printf ("ss\n");
}
