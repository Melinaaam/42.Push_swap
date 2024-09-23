/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/23 14:04:56 by memotyle         ###   ########.fr       */
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
		check_list(&a, av, true);
	}
	else if (ac > 2)
		check_list(&a, av + 1, false);

	if (!list_sorted(a))
	{
		choose_algo(&a, &b);
	}
	ft_printf("list a : \n");
	print_pslist(a);
	ft_printf("list b : \n");
	print_pslist(b);
	free_list(&a);
	//free_list(&b);
	return (0);
}
