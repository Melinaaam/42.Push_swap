/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:43:30 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/12 20:44:59 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// typedef struct s_list
// {
// 	struct s_list	*next;
// 	struct s_list	*prev;
// 	int				nb;

// }	t_titille_la_myrtille;

// typedef struct s_piles
// {
// 	t_titille_la_myrtille pile_a;
// 	t_titille_la_myrtille pile_b;

// }	t_lindia_lesang;

//push_swap
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
void	ft_sa(t_list **a);
void	ft_sb(t_list **b);
void	ft_ss(t_list **a, t_list **b);


//rotate
void	ft_ra(t_list **a);
void	ft_rb(t_list **b);
void	ft_rr(t_list **a, t_list **b);
//reverse
void	ft_rra(t_list **a);
void	ft_rrb(t_list **b);
void	ft_rrr(t_list **a, t_list **b);

//utils
void	free_split(char **split);
int		is_numeric(char *str);
int		neg_to_pos(int nb);
int		revert_neg(int nb);
t_list	ft_merge_lists(t_list **a, t_list *neg, t_list *pos);
void	ft_negative(t_list **a, t_list **b);

//main
void	sort_stack(t_list **a, t_list **b);
int		check_stack(t_list **a, char **split_args);
int		parsing_args(t_list **a, int ac, char **av);

//algos
void	sort_three(t_list **a);
void	ft_radix_sort(t_list **a, t_list **b);
int		ft_max_bits(t_list *a);
void	ft_sort_bits(t_list **a, t_list **b, int bits);
void	ft_push_to_list(t_list **src, t_list **dest);
// int	is_sorted(t_list *a);

void	print_list(t_list *a);
int		is_double(t_list *num, int nb);

#endif
