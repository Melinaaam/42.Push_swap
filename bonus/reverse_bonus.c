/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:45:43 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 11:00:46 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

static	void	ft_reverse_rotate(t_chlist **list)
{
	t_chlist	*temp;
	t_chlist	*head;

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

void	ft_rra(t_chlist **a)
{
	ft_reverse_rotate(a);
	ft_printf ("rra\n");
}

void	ft_rrb(t_chlist **b)
{
	ft_reverse_rotate(b);
	ft_printf ("rrb\n");
}

void	ft_rrr(t_chlist **a, t_chlist **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf ("rrr\n");
}
