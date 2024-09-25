/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/25 19:27:30 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


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
		choose_algo(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
