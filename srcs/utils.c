#include "libft.h"
#include "push_swap.h"

int	size_stack(t_pslist *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}


int	ft_smallest(t_pslist *a)
{
	int	result;

	if (a == NULL)
		return (0);
	result = (a)->nb;
	while(a != NULL)
	{
		if (result > (a)->nb)
			result = (a)->nb;
		a = (a)->next;
	}
	return (result);
}

void	move_smallest(t_pslist **a)
{
	int	smallest;
	int	position;
	int	size;

	smallest = ft_smallest(*a);
	position = position_smallest(*a, smallest);
	size = size_stack(*a);

	if (position > (size / 2))
		ft_rra(a);
	else
		ft_ra(a);
}

int	position_smallest(t_pslist *a, int value)
{
	int position = 0;

	while (a != NULL)
	{
		if (a->nb == value)
			return (position);
		a = a->next;
		position++;
	}
	return(0);
}
