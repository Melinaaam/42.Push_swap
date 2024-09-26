/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:38:26 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 17:30:34 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_double(t_pslist *a, long nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_numeric(char *str)
{
	// ft_printf("str = %s\n", str);
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			//ft_printf("str = %s\n", str);
			return (1);
		}
	return (0);
}

t_pslist	*last_node(t_pslist *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}

void	new_node(int node, t_pslist **list)
{
	t_pslist	*new_node;
	t_pslist	*last;

	if (list == NULL)
		return ;
	new_node = malloc(sizeof(t_pslist));
	if (new_node == NULL)
	{
		free_list(&new_node);
		return ;
	}
	new_node->next = NULL;
	new_node->nb = node;
	if (*list == NULL)
	{
		*list = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = last_node(*list);
		last->next = new_node;
		new_node->prev = last;
	}
}

int	check_list(char **av, bool two_ac, t_pslist **a)
{
	ft_printf("in check : av[0] = %s\n", av[0]);
	ft_printf("in check : av[1] = %s\n", av[1]);
	int			j;
	long		num;

	j = 0;
	while (av[j])
	{
		// ft_printf("av[j] = %s\n", av[j]);
		if (is_numeric(av[j]) == 1)
			ft_error(a, av, two_ac);
		num = ft_atoi(av[j]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(a, av, two_ac);
		if (is_double(*a, num) == 1)
			ft_error(a, av, two_ac);
		new_node((int)num, a);
		j++;
	}
	if (two_ac)
		free_av(av);
	return (1);
}
