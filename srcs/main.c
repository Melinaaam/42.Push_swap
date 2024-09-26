/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 17:35:34 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static bool	list_sorted(t_pslist *a)
{
	if (a == NULL)
		return (true);
	while (a->next)
	{
		if (a->nb > a->next->nb)
			return (false);
		a = a->next;
	}
	return (true);
}

static void	choose_algo(t_pslist **a, t_pslist **b)
{
	int	size;

	size = size_list(*a);
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		sort_three(a);
	else
		algo(a, b);
}

int	main(int ac, char **av)
{
	t_pslist	*a;
	t_pslist	*b;

	a = NULL;
	b = NULL;
	ft_printf("av[0] = %s\n", av[0]);
	ft_printf("av[1] = %s\n", av[1]);
	if (ac == 1 || !av[1][0])
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ft_printf("after split : av[0] = %s\n", av[0]);
		ft_printf("after split : ac = %d\n", ac);
		if (av == NULL)
			exit (EXIT_FAILURE);
	}
	ft_printf("av[0] = %s\n", av[0]);
	ft_printf("ac = %d\n", ac);
	check_list(av + 1, ac == 2, &a);
	if (!list_sorted(a))
		choose_algo(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
