#include "libft.h"
#include "push_swap.h"

int	ft_error(t_pslist **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		//free argument av
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

//free list

void	free_list(t_pslist **a)
{
	t_pslist	*node;
	t_pslist	*temp;

	if(a == NULL || *a == NULL)
		return ;
	node = *a;
	while(node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*a = NULL;
	return ;
}
