/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:38:26 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/25 19:33:27 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

t_chlist	*last_node(t_chlist *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}

int	is_double(t_chlist *a, int nb)
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

void	new_node(int node, t_chlist **list)
{
	t_chlist	*new_node;
	t_chlist	*last;

	if (list == NULL)
		return ;
	new_node = malloc(sizeof(t_chlist));
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

int	check_list(t_chlist **a, char **av, bool two_ac)
{
	int			j;
	long		num;

	j = 0;
	while (av[j])
	{
		if (!is_numeric(av[j]))
			ft_error(a, &av[j], two_ac);
		num = ft_atoi(av[j]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(a, &av[j], two_ac);
		if (is_double(*a, num) == 1)
			ft_error(a, &av[j], two_ac);
		new_node((int)num, a);
		j++;
	}
	if (two_ac)
		free_av(av);
	return (1);
}






