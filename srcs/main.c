/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/13 18:47:02 by memotyle         ###   ########.fr       */
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
		ft_printf("%d\n", *(int *)a->content);
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

	if (ac >= 2)
	{
		ft_printf("before check parsing\n");
		if (!parsing_args(&a, ac, av))
		{
			write(1, "Error\n", 7);
			return (1);
		}
		sort_three (&a);
		lstclear (&a, free);
		// ft_lstclear (&b, free);
	}
	else
		ft_printf("Error\n");
	ft_printf("%d\n", *(int *)a->content);
	return (0);
}
