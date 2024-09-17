/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:43:30 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/17 18:54:45 by melinamotyl      ###   ########.fr       */
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
// void	lstadd_back(t_pslist **lst, t_pslist *new);
// void	lstclear(t_pslist **lst, void (*del)(void*));
int		safe_atoi(const char *str);
int	size_stack(t_pslist *lst);

//parsing
// void	free_split(char **split);
int		is_double(t_pslist *a, int nb);
int		is_numeric(char *str);
t_pslist	*last_node(t_pslist *a);
int	check_stack(t_pslist **a, char **args, bool two_ac);

// static 	t_pslist *ft_new_node(int *nb);

//main
void	print_pslist(t_pslist *a);
void	ft_lstclear_two(t_pslist **lst, void (*del)(void*));
bool	stack_sorted(t_pslist *a);

//error and free
void	free_list(t_pslist **a);
int		ft_error(t_pslist **a, char **av, bool two_ac);
void	free_av(char **av);
#endif
