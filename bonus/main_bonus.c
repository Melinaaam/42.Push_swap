/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:20:22 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 14:04:29 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

bool	list_sorted(t_chlist **a)
{
	t_chlist	*lst_a;

	lst_a = *a;
	if (lst_a == NULL)
		return (true);
	while (lst_a->next)
	{
		if (lst_a->nb > lst_a->next->nb)
			return (false);
		lst_a = lst_a->next;
	}
	return (true);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int ac, char **av)
{
	t_chlist	*a;
	t_chlist	*b;
	t_chlist	*instruction;

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
	check_list(&a, av + 1, false);
	instruction = NULL;
	make_instructions(&instruction, &a, &b);
	if (list_sorted(&a) == true && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(&a);
	free_list(&b);
	return (0);
}
