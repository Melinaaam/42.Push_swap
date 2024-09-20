#include "libft.h"
#include "push_swap.h"

int	ft_smallest_in_b(t_pslist *b)
{
	int	result;

	if (b == NULL)
		return (0);
	result = (b)->nb;
	while(b != NULL)
	{
		if (result > (b)->nb)
			result = (b)->nb;
		b = (b)->next;
	}
	return (result);
}

