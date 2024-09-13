/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/12 13:41:43 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		if (!parsing_args(&a, ac, av))
			return (1);
		// sort_stack (&a, &b);
		ft_negative(&a, &b);
		ft_lstclear (&a, free);
		ft_lstclear (&b, free);
	}
	else
		ft_printf("Error\n");
	return (0);
}
