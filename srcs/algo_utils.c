#include "libft.h"
#include "push_swap.h"

void	partition_a(t_pslist **a, t_pslist **b)
{
	int	mediane;
	int	middle;
	int nb_to_push;

	mediane = find_mediane(*a, size_stack(*a));
	middle = size_stack(*a) - 3;
	nb_to_push = find_mediane_position(*a, mediane, pos_med(*a, mediane));
	//ft_printf("nb_to_push : [%d]\n", nb_to_push);

	while (middle > 0)
	{
		if (nb_to_push != 0)
		{
			while (nb_to_push <= middle && nb_to_push > 0)
			{
				//ft_printf("nb_to_push : [%d]\n", nb_to_push);
				ft_ra(a);
				nb_to_push--;
			}
			while (nb_to_push > middle && nb_to_push < size_stack(*a))
			{
				ft_rra(a);
				nb_to_push++;
			}
		}
		ft_pb(a, b);
		//ft_printf("\nlist b after pb : \n");
		print_pslist(*b);
		//mediane = find_mediane(*a, size_stack(*a));
		nb_to_push = find_mediane_position(*a, mediane, pos_med(*a, mediane));
		middle--;
	}
	sort_three(a);
	push_biggest_in_a(b, a);
	// ft_printf("After partition\n");
	// ft_printf("stack a\n");
	// print_pslist(*a);
	// ft_printf("stack b\n");
	// print_pslist(*b);
}

int	find_biggest(t_pslist *b)
{
	// ft_printf("find biggest OK\n");
	// ft_printf("list b : \n");
	print_pslist(b);
	int	biggest;
	int			i;

	i = INT_MIN;
	biggest = 0;
	if (b == NULL)
		return (-1);
	while(b)
	{
		// ft_printf("list b : \n");
		// print_pslist(b);
		if (i < b->nb)
		{
			biggest = b->nb;
			i = b->nb;
		}
		b = b->next;
	}
	// ft_printf("Biggest in b : {%d}\n", biggest);
	return(biggest);
}

int	position_biggest(t_pslist *b, int big)
{
	// ft_printf("find_biggest OK\n");
	int position = 0;

	big = find_biggest(b);
	// ft_printf("big before while: [%d]\n", big);
	while (b != NULL)
	{
		if (b->nb == big)
		{
			// ft_printf("position : [%d]\n", position);
			return (position);
		}
		b = b->next;
		position++;
	}
	return(0);
}
