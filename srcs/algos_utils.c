#include "libft.h"
#include "push_swap.h"

t_pslist	*lists_gp(t_pslist **a, int size_gp)
{
	ft_printf("lists_gp OK\n");
	t_pslist	*group = NULL;
	t_pslist	*new_node;
	t_pslist	*last;
	t_pslist	*temp_a;
	int			count = 0;

	if (*a == NULL)
	{
		ft_printf("Error : 'a' is NULL" );
		return (NULL);
	}
	temp_a = *a;

	while (temp_a && count < size_gp)
	{
		new_node = (t_pslist *)malloc(sizeof (t_pslist));
		if(!new_node)
			return (NULL);
		if (!a)
		{
			free(new_node);
			return (NULL);
		}

		new_node->nb = (temp_a)->nb;
		new_node->next = NULL;

		ft_printf("new_node->nb : [%d]\n", new_node->nb);

		if (group == NULL)
		{
			group = new_node;
			ft_printf("group commence [%d]", group->nb);
		}
		else
		{
			last = group;
			while(last->next != NULL)
				last = last->next;
			last->next = new_node;
		}
		count++;

		ft_printf("count : [%d]\n", count);

		temp_a = temp_a->next;

		ft_printf("group : \n");
		print_pslist(group);
	}
	return(group);
}

int	find_median(t_pslist *group, t_pslist **b, int size_gp)
{
	ft_printf("find_median ok\n");
	t_pslist	*temp_gp;
	t_pslist	*current;
	int			median;
	int			mid;
	int			i = 0;

	temp_gp = lists_gp(&group, size_gp);
	if(!temp_gp)
		return (-1);

	sort_five(&temp_gp, b);

	mid = (size_gp - 1) / 2;
	current = temp_gp;

	while (i < mid)
	{
		current = current->next;
		i++;
	}
	median = current->nb;
	free_list(&temp_gp);
	return(median);
}
