/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:44:53 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/25 19:29:10 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

void	ft_pa(t_chlist **a, t_chlist **b)
{
	t_chlist	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_printf ("pa\n");
}

void	ft_pb(t_chlist **a, t_chlist **b)
{
	t_chlist	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_printf ("pb\n");
}

void	ft_sa(t_chlist **a)
{
	t_chlist	*temp;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	ft_printf ("sa\n");
}

void	ft_sb(t_chlist **b)
{
	t_chlist	*temp;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	ft_printf ("sb\n");
}

void	ft_ss(t_chlist **a, t_chlist **b)
{
	ft_sa(a);
	ft_sb(b);
	ft_printf ("ss\n");
}
