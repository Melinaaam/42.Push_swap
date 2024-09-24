#include "libft.h"
#include "push_swap.h"

int	size_list(t_pslist *list)
{
	int	i;

	if (list == NULL)
		return (0);
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}


t_pslist	*find_smallest(t_pslist *list)
{
	long	i;
	t_pslist	*result;

	if (list == NULL)
		return (NULL);
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


int	position_smallest(t_pslist *list)
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
	return (position);
}

void	find_closer(t_pslist *a, t_pslist *b)
{
	t_pslist	*temp_a;
	long		landmark;

	if (b == NULL)
		return ;
	while(b)
	{
		landmark = LONG_MAX;
		temp_a = a;
		while(temp_a)
		{
			if(temp_a->nb > b->nb && temp_a->nb < landmark)
			{
				b->closer = temp_a;
				landmark = temp_a->nb;
			}
			temp_a = temp_a->next;
		}
		if (landmark == LONG_MAX)
		{
			b->closer = find_smallest(a);
		}
		b = b->next;
	}
	return ;
}

void	init_true_false_position (t_pslist	*list)
{
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
			list->bellow_mediane = true;
		else
		{
			list->bellow_mediane = false;
		}
		list = list->next;
		i++;
	}
	return ;
}
