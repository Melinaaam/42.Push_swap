#include "libft.h"
#include "push_swap.h"



void	move_to_a(t_pslist	**a, t_pslist **b)
{
	t_pslist	*move;

	move = *b;
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
	sort_a_and_b(a, b, move);
	ft_pa(a, b);
}

void	prepare_algo(t_pslist *a, t_pslist *b)
{
	init_true_false_position(a);
	init_true_false_position(b);
	find_closer(a, b);
	cost_calcul(a, b);
	find_cheapest_cost(b);
}

void	find_cheapest_cost(t_pslist *b)
{
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
	cheapest_node->min = true;
	return ;
}

void	cost_calcul(t_pslist *a, t_pslist *b)
{
	int	len_lst_a;
	int	len_lst_b;

	if (b == NULL)
		return ;
	len_lst_a = size_list(a);
	len_lst_b = size_list(b);
	while(b)
	{
		if (b->bellow_mediane == true)
			b->cost = b->position;
		else
		{
			b->cost = (len_lst_b - (b->position));
		}
		if (b->closer->bellow_mediane == true)
		{
			b->cost += b->closer->position;
		}
		else
		{
			b->cost += (len_lst_a - (b->closer->position));
		}
		b = b->next;
	}
	return;
}
