#include "libft.h"
#include "push_swap.h"

static void	create_tab(t_pslist *a, int **tab, int size_a)
{
	t_pslist	*temp_a;
	int			i;

	temp_a = a;
	i = 0;
	*tab = malloc(sizeof(int) * size_a);
	if (*tab == NULL)
		return ;
	while(i < size_a)
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

int	find_mediane(t_pslist *a, int size_a)
{
	int	*tab;
	int	i;
	int	j;
	int	mediane;

	i = 0;
	j = 0;
	tab = NULL;
	create_tab(a, &tab, size_a);
	if (tab == NULL)
			exit(EXIT_FAILURE);
	sort_intab(&tab, size_a);
	mediane = tab[size_a / 2];
	free(tab);
	return (mediane);
}

int	pos_med(t_pslist *a, int mediane)
{
	int	pos;

	pos = 0;
	while(a->nb != mediane && a->next)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

int	find_position(t_pslist *a, int mediane, int pos_med)
{
	int	pos1;
	int pos2;
	t_pslist	*last;

	if (a == NULL)
		return (-1);
	pos1 = 0;
	pos2 = size_stack(a) - 1;
	while(a->nb > mediane && a->next && pos1 <= pos_med)
	{
		a = a->next;
		pos1++;
	}
	last = last_node(a);
	while (last->nb > mediane && last->prev && pos2 > pos_med)
	{
		last = last->prev;
		pos2--;
	}
	if (pos1 > pos2)
		return(pos2);
	return (pos1);
}


