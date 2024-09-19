/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/19 13:52:47 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

/////////////////////////////////////////////////////////
void	print_pslist(t_pslist *a)
{
	while (a)
	{
		ft_printf("%d\n", a->nb);
		a = a->next;
	}
}
/////////////////////////////////////////////////////////


int	main(int ac, char **av)
{
	t_pslist	*a;
	t_pslist	*b;

	a = NULL;
	b = NULL;

	if (ac == 1 || !av[1][0])
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		check_stack(&a, av, true);
	}
	else if (ac > 2)
		check_stack(&a, av + 1, false);

	if (!stack_sorted(a))
	{
		int	size = size_stack(a);
		//ft_printf("size : [%d]\n", size);
		if (size == 2)
		{
			//ft_printf("before ft_sa\n");
			ft_sa(&a);
			//ft_printf("sort_two ok\n");
		}
		else if (size == 3)
		{
			//ft_printf("before sort three\n");
			sort_three(&a);
			//ft_printf("sort_three ok\n");
		}
		else if (size == 4 || size == 5)
		{
			//ft_printf("before sort five\n");
			sort_five(&a, &b);
			//ft_printf("sort five ok\n");
		}
		else
		{
			ft_printf("create group in main \n", create_group(&a, &b));

			// int median_of_medians = find_median_of_medians;

			// ft_printf("size a after create_group : [%d]\n", size);
			// if (median_of_medians == -999999)
			// {
			// 	ft_printf("Eerror");
			// 	free_list(&a);
			// 	free_list(&b);
			// 	return (1);
			// }

			ft_printf("size a before partition : [%d]\n", size);
			// partition_a(&a, &b, median_of_medians);
			//ft_printf("After create group in main:\n");
			//print_pslist(a);
			//print_pslist(b);
			//fonction pour partitionner a en fonction de la mediane des medianes
			//ex, les elmts < medi des medi dans b, les elmts restants >= restent dans a
			ft_printf("lists after partition : \n");
			print_pslist(a);
			print_pslist(b);
		}
	}
	ft_printf("lists after partition : \n");
	print_pslist(a);
	print_pslist(b);
	// ft_printf("\tprint a fin main : \n");
	// print_pslist(a);
	free_list(&a);
	// print_pslist(b);
	free_list(&b);
	return (0);
}
