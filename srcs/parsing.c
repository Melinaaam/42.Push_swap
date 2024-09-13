/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:38:26 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/12 18:24:59 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}

int	is_double(t_list *a, int nb)
{
	t_list	*head;

	if (!a)
		return (0);
	head = a;
	while (head != NULL)
	{
		// ft_printf("list elem [%d] VS [%d]\n", *head->nb, nb);
		if (*head->nb == nb)
			return (1);
		head = head->next;
	}
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static t_list *ft_new_node(int *nb)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return(NULL);
	list->nb = nb;
	list->next = NULL;
	return(list);
}

int	check_stack(t_list **a, char **split_args)
{
	int		*num;
	int		j;
	t_list	*new_node;

	j = 0;
	while (split_args[j])
	{
		if (is_numeric(split_args[j]) == 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		num = (int *)malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi (split_args[j]);
		// ft_printf("is double ? : [%d]\n", is_double(*a, *num));
		if (is_double(*a, *num) == 1)
		{
			free (num);
			write(2, "Error\n", 6);
			return (0);
		}
		new_node = ft_new_node(num);
		if (!new_node)
		{
			free (num);
			return (0);
		}
		ft_lstadd_back (a, new_node);
		ft_printf("j = %d : arg [%s] -> num [%d]\n", j, split_args[j], num[j]);
		j++;
	}
	return (1);
}

int	parsing_args(t_list **a, int ac, char **av)
{
	int		i;
	char	**split_args;

	i = 1;

	// ft_printf("parsing_args OK\n");

	while (i < ac)
	{
		split_args = ft_split(av[i], ' ');
		if (!split_args || !check_stack(a, split_args))
		{
			free_split(split_args);
			ft_lstclear (a, free);
			return (0);
		}
		free_split(split_args);
		i++;
	}
	return (1);
}
