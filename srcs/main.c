/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/17 19:03:49 by melinamotyl      ###   ########.fr       */
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
		if (a->content)
			ft_printf("%d\n", *(int *)a->content);
		else
			ft_printf("NULL content\n");
		a = a->next;
	}
}
/////////////////////////////////////////////////////////

bool	stack_sorted(t_pslist *a)
{
	ft_printf("stack_sorted ok\n");
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

int	main(int ac, char **av)
{
	t_pslist	*a;
	// t_pslist	*b;

	a = NULL;
	// b = NULL;

	if (ac == 1 || !av[1][0])
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			exit(EXIT_FAILURE);
	}
	check_stack(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
		if (size_stack(a) == 2)
		{
			ft_sa(&a);
			ft_printf("sort_two ok\n");
		}
		else
		{
			sort_three(&a);
			ft_printf("sort_three ok\n");
		}
	}
	print_pslist(a);
	free_list(&a);
	return (0);
}
