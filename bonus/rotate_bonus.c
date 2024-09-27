/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:46:46 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 09:01:15 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static	void	ft_rotate(t_pslist **list)
{
	t_pslist	*temp;
	t_pslist	*head;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	temp = *list;
	*list = (*list)->next;
	head = *list;
	temp->next = NULL;
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = temp;
	*list = head;
}

void	ft_ra(t_pslist **a)
{
	ft_rotate(a);
	ft_printf ("ra\n");
}

void	ft_rb(t_pslist **b)
{
	ft_rotate(b);
	ft_printf ("rb\n");
}

void	ft_rr(t_pslist **a, t_pslist **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf ("rr\n");
}
