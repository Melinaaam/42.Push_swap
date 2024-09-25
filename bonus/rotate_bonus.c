/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:46:46 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/25 19:32:45 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

static	void	ft_rotate(t_chlist **list)
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

void	ft_ra(t_chlist **a)
{
	ft_rotate(a);
	ft_printf ("ra\n");
}

void	ft_rb(t_chlist **b)
{
	ft_rotate(b);
	ft_printf ("rb\n");
}

void	ft_rr(t_chlist **a, t_chlist **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf ("rr\n");
}
