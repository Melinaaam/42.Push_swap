/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:22:28 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/13 18:43:13 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_three(t_pslist **a)
{
	int	first;
	int	second;
	int	third;

	// if (is_sorted(*a))
	// 	return ;

	// ft_printf("sort_three OK\n");

	first = *((int *)(*a)->content);
	second = *((int *)(*a)->next->content);
	third = *((int *)(*a)->next->next->content);

	if (first > second && second < third && first < third)
		ft_sa (a);
	else if (first > second && second < third && first > third)
		ft_ra (a);
	else if (first < second && second > third && first > third)
		ft_rra (a);
	else if (first > second && second > third && first > third)
	{
		ft_sa (a);
		ft_rra (a);
	}
	else if (first < second && second > third && first < third)
	{
		ft_sa (a);
		ft_ra (a);
	}
}

// void	sort_five(t_pslist **a, t_pslist **b)
// {
// 	int	size;

// 	size = ft_lstsize(*a);
// 	if (size != 4 && size != 5)
// 		return ;
// 	if (size == 4)
// 	{
// 		ft_pa(a, b);
// 		sort_three(a);
// 	}
// 	ft_pb(a, b);
// 	else if (size == 5)
// 	{

// 	}
// }
