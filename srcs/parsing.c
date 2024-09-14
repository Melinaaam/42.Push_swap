/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:38:26 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/14 18:17:37 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_double(t_pslist *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		//ft_printf("list elem [%d] VS [%d]\n", *head->nb, nb);
		if (a->nb == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_numeric(char *str)
{
	ft_printf("is_numeric ok\n");
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_pslist	*last_node(t_pslist *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

static t_pslist *new_node(int *node, t_pslist **list)
{
	t_pslist	*new_node;
	t_pslist	*last;

	if (list == NULL)
		return ;
	new_node = malloc(sizeof(t_pslist));
	if (new_node == NULL)
		free_list(new_node);
	new_node->next = NULL;
	new_node->nb = node;

	if (*list == NULL)
	{
		list = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = last_node(list);
		last->next = new_node;
		new_node->prev = last;
	}
}

int	check_stack(t_pslist **a, char **args)
{
	long		num;
	int			j;

	j = 0;
	while (args[j])
	{
		if (is_numeric(args[j]))
			ft_error(a, args[j]);
		num = safe_atoi(args[j]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(a, args[j]);
		if (is_double(*a, num) == 1)
			ft_error(a, args[j]);

		ft_new_node((int)num, *a);
		j++;
	}
	return (1);
}

