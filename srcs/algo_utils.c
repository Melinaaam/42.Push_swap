#include "libft.h"
#include "push_swap.h"

void	partition_a(t_pslist **a, t_pslist **b)
{
	int	mediane;
	int	middle;
	int nb_to_push;

	mediane = find_mediane(*a, size_stack(*a));
	middle = size_stack(*a) - 3;
	nb_to_push = find_position(*a, mediane, pos_med(*a, mediane));

	while (middle > 0)
	{
		if (nb_to_push != 0)
		{
			while (nb_to_push <= middle && nb_to_push > 0)
			{
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
		mediane = find_mediane(*a, size_stack(*a));
		nb_to_push = find_position(*a, mediane, pos_med(*a, mediane));
		middle--;
	}
	//sort_three(a);
	ft_printf("After partition\n");
	ft_printf("stack a\n");
	print_pslist(*a);
	ft_printf("stack b\n");
	print_pslist(*b);
}
