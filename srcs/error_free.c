/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:39:06 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/27 11:56:55 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	free_av(char **av)
{
	int	i;

	if (!av)
		return ;
	i = -1;
	while (av[i])
		free(av[i++]);
	free(av - 1);
	return ;
}

void	free_list(t_pslist **a)
{
	t_pslist	*node;
	t_pslist	*temp;

	if (a == NULL)
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

int	ft_error(t_pslist **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		free_av(av);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}
