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
	struct s_list	*next;
	struct s_list	*prev;
}				t_chlist;

void	ft_pa(t_chlist **a, t_chlist **b);
void	ft_pb(t_chlist **a, t_chlist **b);
void	ft_sa(t_chlist **a);
void	ft_sb(t_chlist **b);
void	ft_ss(t_chlist **a, t_chlist **b);

void	ft_ra(t_chlist **a);
void	ft_rb(t_chlist **b);
void	ft_rr(t_chlist **a, t_chlist **b);

void	ft_rra(t_chlist **a);
void	ft_rrb(t_chlist **b);
void	ft_rrr(t_chlist **a, t_chlist **b);

t_chlist	*last_node(t_chlist *a);
int	is_double(t_chlist *a, int nb);
int	is_numeric(char *str);
void	new_node(int node, t_chlist **list);
int	check_list(t_chlist **a, char **av, bool two_ac);

int	ft_error(t_chlist **a, char **av, bool two_ac);
void	free_av(char **av);
void	free_list(t_chlist **a);
void	free_checker_list(t_chlist **checker_list);
void	free_all(t_chlist **a, t_chlist **b, t_chlist **checker_list);

#endif
