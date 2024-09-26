/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:43:36 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 13:58:24 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

int	check_instructions(char	*instruction, t_chlist	**a, t_chlist **b)
{
	if (ft_strcmp(instruction, "sa") == 0)
		ft_sa(a);
	else if (ft_strcmp(instruction, "sb") == 0)
		ft_sb(b);
	else if (ft_strcmp(instruction, "ss") == 0)
		ft_ss(a, b);
	else if (ft_strcmp(instruction, "pa") == 0)
		ft_pa(a, b);
	else if (ft_strcmp(instruction, "pb") == 0)
		ft_pb(a, b);
	else if (ft_strcmp(instruction, "ra") == 0)
		ft_ra(a);
	else if (ft_strcmp(instruction, "rb") == 0)
		ft_rb(b);
	else if (ft_strcmp(instruction, "rr") == 0)
		ft_rr(a, b);
	else if (ft_strcmp(instruction, "rra") == 0)
		ft_rra(a);
	else if (ft_strcmp(instruction, "rrb") == 0)
		ft_rrb(b);
	else if (ft_strcmp(instruction, "rrr") == 0)
		ft_rrr(a, b);
	else
		return (0);
	return(1);
}

void	make_instructions(t_chlist **instruction, t_chlist **a, t_chlist **b)
{
	t_chlist	*temp;
	char		*s;
	int			verif;
	int			fd;

	verif = 0;
	fd = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s || !*s)
			break ;
		add_instructions(instruction, s);
		free (s);
	}
	if (!instruction)
		return ;
	while (*instruction)
	{
		verif = check_instructions((*instruction)->move, a, b);
		if (verif == 1)
			free_all(a, b, instruction);
		temp = *instruction;
		*instruction = (*instruction)->next;
		free(temp->move);
		free (temp);
	}
}
void	add_instructions(t_chlist **instruction, char *s)
{
	t_chlist	*new_node;
	t_chlist	*last;

	if (instruction == NULL)
		return ;
	new_node = malloc(sizeof(t_chlist));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->move = recup_instruction(s, '\n');
	if (new_node->move == NULL)
	{
		free_instruction(instruction);
		exit (EXIT_FAILURE);
	}
	new_node->prev = NULL;
	if (*instruction == NULL)
		*instruction = new_node;
	else{
		last = last_node(*instruction);
		last->next = new_node;
		new_node->prev = last;
	}
}

char	*recup_instruction(char *s, char c)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(s)));
	if (!cpy)
		return (NULL);
	while (s[i] != c)
	{
		cpy[i] = s[i];
	}
	cpy[i] = '\0';
	return (cpy);
 }
