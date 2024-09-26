/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:54:03 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 11:00:39 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

static	void	ft_swap(t_chlist **list)
{
	t_chlist	*temp;
	t_chlist	*head;

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

void	ft_sa(t_chlist **a)
{
	ft_swap(a);
	ft_printf ("sa\n");
}

void	ft_sb(t_chlist **b)
{
	ft_swap(b);
	ft_printf ("sb\n");
}

void	ft_ss(t_chlist **a, t_chlist **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf ("ss\n");
}
