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
	long		i;
	t_pslist	*result;

	if (list == NULL)
		return (NULL);
	i = LONG_MAX;
	while (list)
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

void	create_tab(t_pslist *a, int **tab, int size_a)
{
	t_pslist	*temp_a;
	int			i;

	temp_a = a;
	i = 0;
	*tab = malloc(sizeof(int) * size_a);
	if (*tab == NULL)
		return ;
	while (i < size_a)
	{
		(*tab)[i] = temp_a->nb;
		temp_a = temp_a->next;
		i++;
	}
}

void	sort_intab(int **tab, int size_a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size_a - 1)
	{
		j = i + 1;
		while (j < size_a)
		{
			if ((*tab)[i] > (*tab)[j])
			{
				temp = (*tab)[i];
				(*tab)[i] = (*tab)[j];
				(*tab)[j] = temp;
			}
			j++;
		}
		i++;
	}
}
