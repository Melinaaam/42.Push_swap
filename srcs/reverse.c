/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:45:43 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/13 18:43:24 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_rra(t_pslist **a)
{
	t_pslist	*temp;
	t_pslist	*head;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = *a;
	while ((*a)->next->next)
		*a = (*a)->next;
	temp = (*a)->next;
	(*a)->next = NULL;
	(*a) = head;
	temp->next = *a;
	*a = temp;
	ft_printf ("rra\n");
}

void	ft_rrb(t_pslist **b)
{
	t_pslist	*temp;
	t_pslist	*head;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	head = *b;
	while ((*b)->next->next)
		*b = (*b)->next;
	temp = (*b)->next;
	(*b)->next = NULL;
	(*b) = head;
	temp->next = *b;
	*b = temp;
	ft_printf ("rrb\n");
}

void	ft_rrr(t_pslist **a, t_pslist **b)
{
	ft_rra (a);
	ft_rrb (b);
	ft_printf ("rrr\n");
}
