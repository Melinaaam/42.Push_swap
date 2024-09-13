/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:39:28 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/12 17:59:33 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	neg_to_pos(int nb)
{
	if (nb < 0)
		return -nb;
	return (nb);
}

int	revert_neg(int nb)
{
	if (nb > 0)
		return -nb;
	return (nb);
}

t_list	ft_merge_lists(t_list **a, t_list *neg, t_list *pos)
{
	// ft_printf("ft_merge_lists OK\n");
	*a = NULL;
	while (pos)
		ft_push_to_list(&pos, a);
	while(neg)
		ft_push_to_list(&neg, a);
	return (**a);
}

void	ft_negative(t_list **a, t_list **b)
{
	// ft_printf("ft_negative OK\n");

	t_list	*neg = NULL;
	t_list	*pos = NULL;

	// ft_printf("\nlist a : \n");
	// print_list(*a);

	while(*a)
	{
		if (*(int *)(*a)->content < 0)
			ft_push_to_list(a, &neg);
		else
			ft_push_to_list(a, &pos);
	}
	// ft_printf("\nlist neg : \n");
	// print_list(neg);
	// ft_printf("\nlist pos 1: \n");
	// print_list(pos);

	t_list *tmp = NULL;
	tmp = neg;

	// ft_printf("\nlist tmp 1: \n");
	// print_list(tmp);

	while(tmp)
	{
		*(int *)tmp->content = neg_to_pos(*(int *)tmp->content);
		tmp = tmp->next;
	}

	// ft_printf("\nlist tmp : \n");
	// print_list(tmp);
	// ft_printf("\nlist neg : \n");
	// print_list(neg);

	// ft_radix_sort(&neg, b);
	// ft_radix_sort(&pos, a);

	sort_stack(&neg, b);
	sort_stack(&pos, a);
	///////////////////////////////////////////////////////////////////////////
	// ft_printf("\nlist neg : \n");
	// print_list(neg);
	// ft_printf("\nlist pos : \n");
	// print_list(pos);

	tmp = neg;

	// ft_printf("\nlist neg : \n");
	// print_list(neg);

	while(tmp)
	{
		*(int *)tmp->content = revert_neg(*(int *)tmp->content);
		tmp = tmp->next;
	}

	// ft_printf("\nlist neg : \n");
	// print_list(neg);

	ft_merge_lists(a, neg, pos);
	// ft_printf("\nlist a : \n");
	// print_list(*a);
}

void	ft_push_to_list(t_list **src, t_list **dest)
{
	t_list *temp;
	t_list *current;
	t_list *previous = NULL;
	int		value;

	if(!src || !*src)
		return ;

	temp = *src;
	*src = (* src)->next;
	temp->next = NULL;
	value = *((int *)temp->content);

	if(!*dest)
	{
		*dest = temp;
		return ;
	}

	current = *dest;
	while(current && *((int *)current->content) < value)
	{
		previous = current;
		current = current->next;
	}

	if (!previous)
	{
		temp->next = *dest;
		*dest = temp;
	}
	else
	{
		previous->next = temp;
		temp->next = current;
	}
}
