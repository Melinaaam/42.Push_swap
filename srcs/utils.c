#include "libft.h"
#include "push_swap.h"

int	size_stack(t_pslist *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

//trouver + petit dans a

int	ft_smallest(t_pslist *a)
{
	ft_printf("smallest OK\n");
	int	result;

	if (a == NULL)
		return (0);
	result = (a)->nb;
	ft_printf("result in ft_smallest : [%d]\n", result);
	while(a != NULL)
	{
		if (result > (a)->nb)
			result = (a)->nb;
		a = (a)->next;
	}
	return (result);
}

//pousser le + petit elmt de a dans b
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

//trouver position du plus petit elmt de a
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
