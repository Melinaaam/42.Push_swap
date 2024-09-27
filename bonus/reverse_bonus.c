/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:45:43 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 09:40:21 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static	void	ft_reverse_rotate(t_pslist **list)
{
	t_pslist	*temp;
	t_pslist	*head;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	head = *list;
	while ((*list)->next->next)
		*list = (*list)->next;
	temp = (*list)->next;
	(*list)->next = NULL;
	(*list) = head;
	temp->next = *list;
	*list = temp;
}

void	ft_rra(t_pslist **a)
{
	ft_reverse_rotate(a);
	ft_printf ("rra\n");
}

void	ft_rrb(t_pslist **b)
{
	ft_reverse_rotate(b);
	ft_printf ("rrb\n");
}

void	ft_rrr(t_pslist **a, t_pslist **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf ("rrr\n");
}
