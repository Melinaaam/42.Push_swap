/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/18 19:43:43 by melinamotyl      ###   ########.fr       */
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
	t_pslist	*group;

	a = NULL;
	b = NULL;
	group = NULL;

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
			ft_printf("algo a venir\n");
			group = lists_gp(&a, 5);
			if (!group)
			{
				ft_printf("lists_gp failed\n");
				free_list(&a);
				return (1);
			}
			//a revoir pour :
			//gestion des groups
			//trier les groups
			//trouver la mediane
			//trouver la mediane des medianes
			//trier a en fonction de la mediane des medianes
		}
	}
	ft_printf("print a fin main : \n");
	print_pslist(a);
	free_list(&a);
	// print_pslist(b);
	// free_list(&b);
	return (0);
}
