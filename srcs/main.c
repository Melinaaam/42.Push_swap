/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/27 22:30:54 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		neg;
	long	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (nb * neg);
}

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
	if (ac == 1 || !av[1][0])
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			exit (EXIT_FAILURE);
	}
	check_list(av + 1, ac == 2, &a);
	if (!list_sorted(a))
		choose_algo(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
