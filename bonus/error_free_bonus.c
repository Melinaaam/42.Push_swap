/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:43:13 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/27 11:56:31 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

int	ft_error(t_chlist **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		free_av(av);
	write(2, "Error1\n", 6);
	exit(EXIT_FAILURE);
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_list(t_chlist **a)
{
	t_chlist	*node;
	t_chlist	*temp;

	if (a == NULL || *a == NULL)
		return ;
	node = *a;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*a = NULL;
	return ;
}

void	free_instruction(t_chlist **instruction)
{
	t_chlist	*node;
	t_chlist	*temp;

	if (instruction == NULL || *instruction == NULL)
		return ;
	node = *instruction;
	while (node)
	{
		temp = node->next;
		free(node->move);
		free(node);
		node = temp;
	}
}

void	free_all(t_chlist **a, t_chlist **b, t_chlist **checker_list)
{
	free_list(a);
	free_list(b);
	free_instruction(checker_list);
	exit(EXIT_FAILURE);
}
