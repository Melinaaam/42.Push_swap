#include "libft.h"
#include "push_swap.h"

t_pslist	*lists_gp(t_pslist **a, int size_gp)
{
	//fonction qui cree neud pour chaque group
	//voir si variable int size_gp ets necessaire
	ft_printf("lists_gp OK\n");
	t_pslist	*group = NULL;
	t_pslist	*new_node;
	t_pslist	*last;
	t_pslist	*temp_a = *a;
	int			count = 0;

	// if (temp_a == NULL)
	// {
	// 	ft_printf("Error : 'a' is NULL\n" );
	// 	return (NULL);
	// }

	while (temp_a && count < size_gp)
	{
		new_node = (t_pslist *)malloc(sizeof (t_pslist));
		if(!new_node)
			return (NULL);

		new_node->nb = temp_a->nb;
		new_node->next = NULL;

		ft_printf("new_node->nb : [%d]\n", new_node->nb);

		if (group == NULL)
		{
			group = new_node;
			ft_printf("group commence [%d]\n", group->nb);
		}
		else
		{
			last = group;
			while(last->next != NULL)
				last = last->next;
			last->next = new_node;
		}
		temp_a = temp_a->next;
		count++;

		ft_printf("count : [%d]\n", count);

		ft_printf("group : \n");
		print_pslist(group);
	}
	ft_printf("end of lists_gp\n\n");
	ft_printf("size a a la fin de lists_group : [%d]\n", size_stack(*a));
	return(group);
}

int	find_median(t_pslist *group, int size_gp)
{
	//fonction qui sert a trouver chaque mediane de chaque groupe
	ft_printf("\nfind_median ok\n");
	t_pslist	*temp_gp = group;
	int			mid = (size_gp - 1) / 2;
	int			i = 0;

// 	int num_groups = (total_size + 4) / 5;

// 	int *medians = (int *)malloc(sizeof(int) * num_groups);
// 	if(!medians)
// 		return (-999999);

// 	int count_gp = 0;

	while (i < mid)
	{
		temp_gp = temp_gp->next;
		i++;
	}
	ft_printf("temp_gp->nb : [%d]\n", temp_gp->nb);
	ft_printf("end of find_median\n\n");
	int median = find_median(group, current_group_size);

// 	medians[count_gp++] = median;

// 	int i = 0;
// 	while (i < count_gp)
// 	{
// 		i++;
// 	}
// 	total_size -= current_group_size;

// 	free_list(&group);
// 	}
// 	int median_of_medians = find_median_of_medians(medians, num_groups);

// 	free(medians);

// 	return (median_of_medians);
// }

	return(temp_gp->nb);
}

t_pslist	create_group(t_pslist **a, t_pslist **b)
{
	//cree des groupes de 5 en fonction du contenu de a
	ft_printf("create_group ok\n");
	int total_size = size_stack(*a);
	int group_size = 5;
	t_pslist *group = NULL;

	ft_printf("total_size : [%d]\n", total_size);
	ft_printf("group_size : [%d]\n\n", group_size);

	while(total_size > 0)
	{
		//divise en group de 5
		int current_group_size;

		if (total_size >= group_size)
			{
				current_group_size = group_size;//si 5 ou plus
				ft_printf("current_group_size : [%d]\n\n", current_group_size);
			}
		else
			{
				current_group_size = total_size;//si - de 5
				ft_printf("current_group_size : [%d]\n", current_group_size);
			}
	t_pslist *group = lists_gp(a, current_group_size);

	ft_printf("group after lists_gp in create group: \n");
	print_pslist(group);

	//trier le groupe avant de chercher la mediane
	if (current_group_size == 5 || current_group_size == 4)
		{
			sort_five(&group, b);
			ft_printf("group after sort_five in create group: \n");
			print_pslist(group);
		}
	else
		{
			sort_three(&group);
			ft_printf("group after sort_three in create group: \n");
			print_pslist(group);
		}
	free_list(&group);
	}
	return (*group);
}

int	find_median_of_medians(t_pslist	**a, t_pslist **b)
{
	ft_printf("\nfind_median_of_medians ok\n");
	t_pslist	*group;

	*group = create_group(&a, &b);
	//obtenir mes groupes tries grace a create_group : creat_group cree et tri autant de groupe de 5 elemts que necessaire en fonction du contenu de a
	int	medians = find_median;//(group, //int size_gp?)
	//trouver chaque mediane

	//faire le bubbke sort ci dessous :
	bubble_sort(medians, num_groups);

	int mid_index = (num_groups - 1) / 2;

	ft_printf("mid_index : [%d]\n", mid_index);
	if (num_groups % 2 == 0)
		return (medians[mid_index]);
	else
		return (medians[mid_index] + medians[mid_index + 1]) / 2;
	ft_printf("medians[mid_index] : [%d]\n", medians[mid_index]);
}

void bubble_sort(int arr[], int n)
{
	ft_printf("bubble_sort ok\n");
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
void	partition_a(t_pslist **a, t_pslist **b, int median_of_medians)
{
	//partitionner a en fonction de la mediane des medianes obtenu grace a find_median_of_medians
	ft_printf("\npartition OK\n");

	if (*a == NULL)
	{
		ft_printf("error, a is NULL\n");
		return ;
	}

	int	original_size_a = size_stack(*a);

	ft_printf("original_size_a [%d]\n", original_size_a);

	int i = 0;

	while(i < original_size_a)
	{
		if (*a == NULL)
		{
			ft_printf("Error, a became Null during partition");
			break;
		}
		if ((*a)->nb < median_of_medians)
			ft_pb(a, b);
		else
			ft_ra(a);
		// (*a) = (*a)->next;
		i++;
	}
	ft_printf("partition completed\n");
	ft_printf("list a after partition : \n");
	print_pslist(*a);
	ft_printf("list b after partition : \n");
	print_pslist(*b);
}
// int	create_group(t_pslist **a, t_pslist **b)
// {
// 	ft_printf("create_group ok\n");
// 	int total_size = size_stack(*a);
// 	int group_size = 5;

// 	int num_groups = (total_size + 4) / 5;

// 	int *medians = (int *)malloc(sizeof(int) * num_groups);
// 	if(!medians)
// 		return (-999999);

// 	ft_printf("total_size : [%d]\n", total_size);
// 	ft_printf("group_size : [%d]\n\n", group_size);

// 	int count_gp = 0;

// 	while(total_size > 0)
// 	{
// 		//divise en group de 5
// 		int current_group_size;

// 		if (total_size >= group_size)
// 			{
// 				current_group_size = group_size;//si 5 ou plus
// 				ft_printf("current_group_size : [%d]\n\n", current_group_size);
// 			}
// 		else
// 			{
// 				current_group_size = total_size;//si - de 5
// 				ft_printf("current_group_size : [%d]\n", current_group_size);
// 			}
// 	t_pslist *group = lists_gp(a, current_group_size);

// 	ft_printf("group after lists_gp in create group: \n");
// 	print_pslist(group);

// 	//trier le groupe avant de chercher la mediane
// 	if (current_group_size == 5 || current_group_size == 4)
// 		{
// 			sort_five(&group, b);
// 			ft_printf("group after sort_five in create group: \n");
// 			print_pslist(group);
// 		}
// 	else
// 		{
// 			sort_three(&group);
// 			ft_printf("group after sort_three in create group: \n");
// 			print_pslist(group);
// 		}
// 	int median = find_median(group, current_group_size);
// 	ft_printf("median : [%d]\n", find_median(group, current_group_size));
// 	ft_printf("current_group_size:[%d] \n", current_group_size);

// 	medians[count_gp++] = median;

// 	int i = 0;
// 	while (i < count_gp)
// 	{
// 		ft_printf("medians[%d] : [%d]\n", i, medians[i]);
// 		i++;
// 	}
// 	total_size -= current_group_size;

// 	free_list(&group);
// 	}
// 	int median_of_medians = find_median_of_medians(medians, num_groups);
// 	ft_printf("median_of_medians : [%d]\n", median_of_medians);
// 	free(medians);
// 	ft_printf("size a a la fin de create group : [%d]\n", size_stack(*a));
// 	return (median_of_medians);
// }
