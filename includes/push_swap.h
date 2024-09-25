/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:43:30 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/25 19:06:03 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include <limits.h>

typedef struct ps_list
{
	struct ps_list	*next;
	struct ps_list	*prev;
	struct ps_list	*closer;
	int				nb;
	int				position;
	int				cost;
	bool			min;
	bool			mediane;
}				t_pslist;

//swap_and_push
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

//parsing
int		is_double(t_pslist *a, int nb);
int		is_numeric(char *str);
void	new_node(int node, t_pslist **list);
int		check_list(t_pslist **a, char **args, bool two_ac);
t_pslist	*last_node(t_pslist *a);

//utils
t_pslist	*find_smallest(t_pslist *list);
int		size_list(t_pslist *list);
int		position_smallest(t_pslist *list);
void	create_tab(t_pslist *a, int **tab, int size_a);
void	sort_intab(int **tab, int size_a);

//error and free
void	free_list(t_pslist **a);
int		ft_error(t_pslist **a, char **av, bool two_ac);
void	free_av(char **av);

//algos
void	prepare_algo(t_pslist *a, t_pslist *b);
void	sort_three(t_pslist **a);
void	sort_a_and_b(t_pslist	**a, t_pslist **b, t_pslist *move);
void	algo(t_pslist **a, t_pslist **b);

//algo utils
void	init_true_false_position(t_pslist	*list);
void	find_closer(t_pslist *a, t_pslist *b);
void	cost_calcul(t_pslist *a, t_pslist *b);
void	find_cheapest_cost(t_pslist *b);
void	move_to_a(t_pslist	**a, t_pslist **b);

//mediane
void	partition_a(t_pslist **a, t_pslist **b);
void	move_to_top(t_pslist **a, int moves_to_top, int middle);
int		find_mediane(t_pslist *a, int size_a);
int		pos_med(t_pslist *a, int mediane);
int		find_position(t_pslist *a, int mediane, int pos_med);

#endif
