/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:22:28 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/12 20:47:44 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_three(t_list **a)
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

void	ft_radix_sort(t_list **a, t_list **b)
{
	// ft_printf("ft_radix_sort OK\n");

	int	bits;
	int	found_bits;

	bits = 0;
	found_bits = ft_max_bits(*a);
	while (bits < found_bits)
	{
		ft_sort_bits(a, b, bits);
		bits++;
	}
}

int	ft_max_bits(t_list *a)
{
	int	max_value;
	int	bits;
	int	compare_value;

	max_value = *((int *)(a->content));//pour le moment max a la valeur du 1er elmt de la liste
	bits = 0;

	while (a)
	{
		compare_value = *((int *)(a->content));//commence la comparaison a venir avec 1er elmt de la liste
		if(compare_value > max_value)
			max_value = compare_value;//on reajuste la valeur de max_value si compare_value est plus grand
		a = a->next;
	}
	while (max_value >> bits)
		bits++;//compte le nb de bits dans max_value
	return (bits);//retourne le nombre de bits dans la plus grande valeure
}

void	ft_sort_bits(t_list **a, t_list **b, int bits)
{
	int	size;
	int	i;
	int	moves_to_b;

	size = ft_lstsize(*a);
	i = 0;//"index" itere elmts de la liste
	moves_to_b = 0;//compter le nombre d'elmts dans b
	while(i++ < size)
	{
		if((*((int *)((*a)->content)) >> bits) & 1)//verifi si bit a comparer est 1
			ft_ra (a);
		else
		{
			ft_pb(a, b);
			moves_to_b++;
		}
	}
	while (moves_to_b-- > 0)//on remet les elmts de b dans a
		ft_pa (a, b);
}


void	sort_stack(t_list **a, t_list **b)
{
	int		list_size;

	list_size = ft_lstsize (*a);

	if (list_size == 0 || list_size == 1)
		return ;

	if (list_size == 2)
	{
		if (*((int *)(*a)->content) > *((int *)(*a)->next->content))
			ft_sa (a);
		return ;
	}
	
	// ft_printf("sort_stack OK\n");
	// ft_printf("list_size = %d\n", list_size);

	if (list_size <= 3)
		sort_three (a);
	// else if (list_size >= 4 && list_size <= 5)
	// 	sort_five (a, b);
	else if (list_size >= 4 && list_size <= 100)
		ft_radix_sort (a, b);
	else
	{
		write(2, "Error\n", 6);
		ft_lstclear (a, free);
		ft_lstclear (b, free);
	}
}


