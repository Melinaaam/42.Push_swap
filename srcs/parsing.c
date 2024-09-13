/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:38:26 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/13 18:49:31 by memotyle         ###   ########.fr       */
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

int	is_double(t_pslist *a, int *nb)
{
	t_pslist	*head;

	if (!a)
		return (0);
	head = a;
	while (head != NULL)
	{
		//ft_printf("list elem [%d] VS [%d]\n", *head->nb, nb);
		if (head->content == nb)
			return (1);
		head = head->next;
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
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static t_pslist *ft_new_node(int *number)
{
	ft_printf("ft_new_node OK\n");
	t_pslist	*list;

	list = (t_pslist *)malloc(sizeof(t_pslist));
	if (list == NULL)
		return(NULL);
	list->content = number;
	list->next = NULL;
	return(list);
}

int	check_stack(t_pslist **a, char **args)
{
	ft_printf("check_stack ok\n");
	int			num;
	int			j;
	t_pslist		*new_node;

	j = 0;
	while (args[j])
	{
		if (is_numeric(args[j]) == 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		// num = (int *)malloc(sizeof(int));
		// if (!num)
		// 	return (0);
		ft_printf("return in check_stack after is_num\n");
		ft_printf("args[j] = [%s]\n", args[j]);
		num = ft_atoi (args[j]);
		ft_printf("num : [%d]\n", num);
		if (is_double(*a, &num) == 1)
		{
			// free (num);
			write(2, "Error\n", 6);
			return (0);
		}
		new_node = ft_new_node(&num);
		ft_printf("new_node : [%d]\n", new_node->content);
		if (!new_node)
		{
			// free (num);
			return (0);
		}
		lstadd_back (a, new_node);
		// ft_printf("\t liste a : \n");
		// print_pslist(*a);
		// ft_printf("j : [%d]\n", j);
		j++;
	}
	return (1);
}

int	parsing_args(t_pslist **a, int ac, char **av)
{
	int		i;
	char	**split_args;

	i = 1;
	ft_printf("parsing_args OK\n");

	while (i < ac)
	{
		ft_printf("Before split\n");
		split_args = ft_split(av[i], ' ');
		if (!split_args || !check_stack(a, split_args))
		{
			free_split(split_args);
			lstclear (a, free);
			return (0);
		}
		free_split(split_args);
		i++;
	}
	return (1);
}
