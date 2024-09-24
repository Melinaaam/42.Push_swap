#include "libft.h"
#include "push_swap.h"
void	print_list(t_pslist *list)
{
	if (list == NULL)
		return ;
	while (list)
	{
		ft_putnbr(list->nb);
		ft_putchar('\n');
		list = list->next;
	}
}

void	partition_a(t_pslist **a, t_pslist **b)
{
	int	mediane;
	int	middle_list;
	int moves_to_top;

	ft_printf("list a : \n");
	print_list(*a);
	ft_printf("list b : \n");
	print_list(*b);

	mediane = find_mediane(*a, size_list(*a));
	middle_list = size_list(*a) / 2;
	moves_to_top = find_position(*a, mediane, pos_med(*a, mediane));

	ft_printf("mediane = %d\n", mediane);
	ft_printf("middle = %d\n", middle_list);
	ft_printf("pos_med = %d\n", pos_med(*a, mediane));

	while (middle_list > 0 && size_list(*a) > 3)
	{
		ft_printf("moves_to_top = %d\n", moves_to_top);
		if (moves_to_top != 0)
		{
			while (moves_to_top <= middle_list && moves_to_top > 0)
			{
				ft_ra(a);
				moves_to_top--;
			}
			while (moves_to_top > middle_list && moves_to_top < size_list(*a))
			{
				ft_rra(a);
				moves_to_top++;
			}
			ft_printf("list a : \n");
			print_list(*a);
			ft_printf("list b : \n");
			print_list(*b);
			ft_printf("moves_to_top = %d\n", moves_to_top);
		}
		ft_pb(a, b);
		mediane = find_mediane(*a, size_list(*a));
		moves_to_top = find_position(*a, mediane, pos_med(*a, mediane));
		ft_printf("_____________________________\n");
		ft_printf("mediane = %d\n", mediane);
		ft_printf("moves_to_top = %d\n", moves_to_top);
		ft_printf("middle = %d\n", middle_list);
		ft_printf("list a : \n");
		print_list(*a);
		ft_printf("list b : \n");
		print_list(*b);
		middle_list--;
	}
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
	int	mediane;

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
	pos2 = size_list(a) - 1;
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
	{
		return(pos2);
	}
	// else if (pos2 == 0 && pos1 == size_list(a))
	// 	return (-1);
	return (pos1);
}
