/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:46:46 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/09 13:50:04 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ra(t_list **a)
{
	t_list	*temp;
	t_list	*head;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	head = *a;
	temp->next = NULL;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = temp;
	*a = head;
	ft_printf ("ra\n");
}

void	ft_rb(t_list **b)
{
	t_list	*temp;
	t_list	*head;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	head = *b;
	temp->next = NULL;
	while ((*b)->next)
		*b = (*b)->next;
	(*b)->next = temp;
	*b = head;
	ft_printf ("rb\n");
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_ra (a);
	ft_rb (b);
	ft_printf ("rr\n");
}
