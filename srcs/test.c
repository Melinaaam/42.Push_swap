#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

void	print_list(t_list *a)
{
	while (a)
	{
		printf("%d\n", *(int *)a->content);
		a = a->next;
	}
}


// int	is_sorted(t_list *a)
// {
// 	int	first;
// 	int	second;
// 	int	third;

// 	// ft_printf("is_sorted OK\n");

// 	first = *((int *)a->content);
// 	second = *((int *)a->next->content);
// 	third = *((int *)a->next->next->content);
// 	if (first < second && second < third)
// 		return (1);
// 	return (0);
// }


// void	sort_five(t_list **a, t_list **b)
// {
// 	int	size;

// 	size = ft_lstsize(*a);
// 	if (size != 4 && size != 5)
// 		return ;
// 	push_smallest_to_b (a, b);
// 	if (size == 5)
// 		push_smallest_to_b (a, b);
// 	sort_three(a);
// 	ft_pa(a, b);
// 	if (size == 5)
// 		ft_pa(a, b);
// }
