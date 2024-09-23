#include "libft.h"
#include "push_swap.h"

void	partition_a(t_pslist **a, t_pslist **b)
{
	int	mediane;
	int	middle;
	int position;

	mediane = find_mediane(*a, size_list(*a));
	middle = size_list(*a) - 3;
	position = find_position(*a, mediane, pos_med(*a, mediane));

	while (middle > 0)
	{
		if (position != 0)
		{
			while (position <= middle && position > 0)
			{
				ft_ra(a);
				position--;
			}
			while (position > middle && position < size_list(*a))
			{
				ft_rra(a);
				position++;
			}
		}
		ft_pb(a, b);
		position = find_position(*a, mediane, pos_med(*a, mediane));
		middle--;
	}
	sort_three(a);
}

void	move_to_a(t_pslist	**a, t_pslist **b)
{
	t_pslist	*move;

	move = *b;
	if (move == NULL)
		return;
	while(move)
	{
		if (move->min == true)
			break;
		move = move->next;
	}
	if (move->bellow_mediane == true && move->closer->bellow_mediane == true)
	{
		while (move != *b && move->closer != *a)
			ft_rr(a, b);
		prepare_algo(*a, *b);
	}
	else if (!(move->bellow_mediane) && !(move->closer->bellow_mediane))
	{
		while(move != *b && move->closer != *a)
			ft_rrr(a, b);
		prepare_algo(*a, *b);
	}
	//sort_a_and_b(a, b, move);
	//ft_pa(a, b);
}

void	prepare_algo(t_pslist *a, t_pslist *b)
{
	ft_printf("prepare_algo ok\n");
	init_true_false_position(a);
	init_true_false_position(b);
	find_closer(a, b);
	cost_calcul(a, b);
	find_cheapest_cost(b);
}

void	find_cheapest_cost(t_pslist *b)
{
	ft_printf("find_cheapest_cost ok\n");
	t_pslist	*cheapest_node;
	long		i;

	if (b == NULL)
		return;
	cheapest_node = NULL;
	i = LONG_MAX;
	while(b)
	{
		if (b->cost < i)
		{
			cheapest_node = b;
			i = b->cost;
		}
		b = b->next;
	}
	ft_printf("cheapest_node->nb = %d\n", cheapest_node->nb);
	cheapest_node->min = true;
	return ;
}

void	cost_calcul(t_pslist *a, t_pslist *b)
{
	ft_printf("cost_calcul ok\n");
	int	len_lst_a;
	int	len_lst_b;

	len_lst_a = size_list(a);
	len_lst_b = size_list(b);
	while(b)
	{
		b->cost = b->position;
		if(b->bellow_mediane == true)
		{
			b->cost += b->closer->position;
		}
		if (b->closer->bellow_mediane == false)
		{
			b->cost = size_list(b) - (b->position);
		}
		else
		{
			b->cost = size_list(a) - (b->closer->position);
		}
		b = b->next;
	}
	return;
}
