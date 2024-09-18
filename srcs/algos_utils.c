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
		ft_printf("Error : 'a' is NULL\n" );
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

int	find_median(t_pslist *group, int size_gp)
{
	ft_printf("find_median ok\n");
	t_pslist	*temp_gp = group;
	int			mid = (size_gp - 1) / 2;
	int			i = 0;

	while (i < mid)
	{
		temp_gp = temp_gp->next;
		i++;
	}
	return(temp_gp->nb);
}

void	create_group(t_pslist **a, t_pslist **b)
{
	int total_size = size_stack(*a);
	int group_size = 5;
	int medians[total_size / 5 + 1];
	int num_groups = 0;

	while(total_size > 0)
	{
		//divise en group de 5
		int current_group_size;

		if (total_size >= group_size)
			current_group_size = group_size;//si 5 ou plus
		else
			current_group_size = total_size;//si - de 5
	t_pslist *group = lists_gp(a, current_group_size);

	//trier le groupe avant de chercher la mediane
	if (current_group_size == 5 || current_group_size == 4)
		sort_five(&group, b);
	else
		sort_three(&group);
	int median = find_median(group, current_group_size);
	medians[num_groups++] = median;

	total_size -= current_group_size;

	free_list(&group);
	}
	int median_of_medians = find_median_of_medians(medians, num_groups);//fonction a creer
	ft_printf("median_of_medians : [%d]\n", median_of_medians);
}

int	find_median_of_medians(int *medians, int num_groups)
{
	ft_printf("find_median_of_medians ok\n");
	bubble_sort(medians, num_groups);

	int mid_index = (num_groups - 1) / 2;

	if (num_groups % 2 == 0)
		return (medians[mid_index]);
	else
		return (medians[mid_index] + medians[mid_index + 1]) / 2;
}

void bubble_sort(int arr[], int n)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
