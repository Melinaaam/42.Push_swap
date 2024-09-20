#include "libft.h"
#include "push_swap.h"

int	ft_error(t_pslist **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		free_av(av);
	write(2, "Error\n", 6);
	return (0);
}

void	free_av(char **av)
{
	ft_printf("free-av ok");
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_list(t_pslist **a)
{
	ft_printf("free list ok");
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
