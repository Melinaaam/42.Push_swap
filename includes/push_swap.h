/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:43:30 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/18 16:22:47 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

# include "libft.h"

#ifndef INT_MAX
# define INT_MAX 2147483647
#endif

#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

typedef struct ps_list
{
	struct ps_list	*next;
	struct ps_list	*prev;
	int				*content;
	int				nb;
	bool 			min;
}				t_pslist;

//push_and_swap
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

//algos utils
t_pslist	*lists_gp(t_pslist **a, int size_gp);
int	find_median(t_pslist *group, t_pslist **b, int size_gp);


//algos
bool	stack_sorted(t_pslist *a);
void	sort_three(t_pslist **a);
void	sort_five(t_pslist **a, t_pslist **b);

//error and free
void	free_list(t_pslist **a);
int		ft_error(t_pslist **a, char **av, bool two_ac);
void	free_av(char **av);

//main
void	print_pslist(t_pslist *a);

//parsing
int		is_double(t_pslist *a, int nb);
int		is_numeric(char *str);
t_pslist	*last_node(t_pslist *a);
void new_node(int node, t_pslist **list);
int	check_stack(t_pslist **a, char **args, bool two_ac);

//utils
int	size_stack(t_pslist *lst);
int	ft_smallest(t_pslist *a);
void	move_smallest(t_pslist **a);
int	position_smallest(t_pslist *a, int value);

#endif
