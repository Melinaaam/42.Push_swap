/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:41:51 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/26 14:04:10 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct c_list
{
	int				nb;
	char			*move;
	struct c_list	*next;
	struct c_list	*prev;
}				t_chlist;

//push
void	ft_pa(t_chlist **a, t_chlist **b);
void	ft_pb(t_chlist **a, t_chlist **b);

//reverse
void	ft_rra(t_chlist **a);
void	ft_rrb(t_chlist **b);
void	ft_rrr(t_chlist **a, t_chlist **b);

//rotate
void	ft_ra(t_chlist **a);
void	ft_rb(t_chlist **b);
void	ft_rr(t_chlist **a, t_chlist **b);

//swap
void	ft_sa(t_chlist **a);
void	ft_sb(t_chlist **b);
void	ft_ss(t_chlist **a, t_chlist **b);

//ft_error
int			ft_error(t_chlist **a, char **av, bool two_ac);
void		free_av(char **av);
void		free_list(t_chlist **a);
void		free_instruction(t_chlist **instruction);
void		free_all(t_chlist **a, t_chlist **b, t_chlist **checker_list);

//main
int			ft_strcmp(const char *s1, const char *s2);
bool		list_sorted(t_chlist **a);
//parsing
t_chlist	*last_node(t_chlist *a);
int			is_double(t_chlist *a, int nb);
int			is_numeric(char *str);
void		new_node(int node, t_chlist **list);
int			check_list(t_chlist **a, char **av, bool two_ac);

//utils
int			check_instructions(char	*instruction, t_chlist	**a, t_chlist **b);
int			ft_strcmp(const char *s1, const char *s2);
void		make_instructions(t_chlist **instruction, t_chlist **a, t_chlist **b);
void		add_instructions(t_chlist **instruction, char *s);
char		*recup_instruction(char *s, char c);

#endif
