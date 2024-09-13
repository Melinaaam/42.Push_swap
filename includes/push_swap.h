/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:43:30 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/13 18:49:09 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct ps_list
{
	struct ps_list	*next;
	struct ps_list	*prev;
	int				*content;
}				t_pslist;

//push_swap
void	ft_pa(t_pslist **a, t_pslist **b);
void	ft_pb(t_pslist **a, t_pslist **b);
void	ft_sa(t_pslist **a);
void	ft_sb(t_pslist **b);
void	ft_ss(t_pslist **a, t_pslist **b);

//rotate
void	ft_ra(t_pslist **a);
void	ft_rb(t_pslist **b);
void	ft_rr(t_pslist **a, t_pslist **b);

//reverse
void	ft_rra(t_pslist **a);
void	ft_rrb(t_pslist **b);
void	ft_rrr(t_pslist **a, t_pslist **b);

//algos
void	sort_three(t_pslist **a);
// void	sort_five(t_pslist **a, t_pslist **b);

//utils
void lstadd_back(t_pslist **lst, t_pslist *new);
void lstclear(t_pslist **lst, void (*del)(void*));

//parsing
void	free_split(char **split);
int		is_double(t_pslist *a, int *nb);
int		is_numeric(char *str);
// static 	t_pslist *ft_new_node(int *nb);
int		check_stack(t_pslist **a, char **split_args);
int		parsing_args(t_pslist **a, int ac, char **av);

//main
void	print_pslist(t_pslist *a);
void	ft_lstclear_two(t_pslist **lst, void (*del)(void*));

#endif
