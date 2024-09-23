#include "libft.h"
#include "push_swap.h"

int	size_list(t_pslist *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}


t_pslist	*find_smallest(t_pslist *list)
{
	long	i;
	t_pslist	*result;

	if (list == NULL)
		return (0);
	i = LONG_MAX;
	while(list)
	{
		if (list->nb < i)
		{
			i = list->nb;
			result = list;
		}
		list = list->next;
	}
	return (result);
}


void	position_smallest(t_pslist *list)
{
	int	position;
	int	smallest;

	smallest = find_smallest(list)->nb;
	position = 0;
	while (list)
	{
		if (list->nb == smallest)
			break;
		position++;
		list = list->next;
	}
}

void	find_closer(t_pslist *a, t_pslist *b)
{
	ft_printf("find_closer ok\n");
	t_pslist	*temp_a;
	t_pslist	*closer;
	long		landmark;

	while(b)
	{
		landmark = LONG_MAX;
		temp_a = a;
		while(temp_a)
		{
			if(temp_a->nb > b->nb && temp_a->nb < landmark)
			{
				landmark = temp_a->nb;
				closer = temp_a;

			}
			temp_a = temp_a->next;
		}
		if (landmark == LONG_MAX)
			{
				b->closer = find_smallest(a);
			}
		else
			b->closer = closer;
		b = b->next;
	}
	return ;
}

void	init_true_false_position (t_pslist	*list)
{
	ft_printf("init_true_false_position ok\n");
	int	i;
	int	mediane;

	i = 0;
	if (list == NULL)
		return;
	mediane = size_list(list) / 2;
	while (list)
	{
		list->position = i;
		if (i <= mediane)
			{
				list->bellow_mediane = true;
				ft_printf("list->bellow_mediane = true\n");
			}
		else
		{
			list->bellow_mediane = false;
			ft_printf("list->bellow_mediane = false\n");
		}
		list = list->next;
		i++;
	}
	return ;
}
