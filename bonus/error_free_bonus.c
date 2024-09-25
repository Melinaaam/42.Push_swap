#include "libft.h"
#include "checker_bonus.h"

int	ft_error(t_chlist **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		free_av(av);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_av(char **av)
{
	int	i;

	i = -1;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av - 1);
	return ;
}

void	free_list(t_chlist **a)
{
	t_chlist	*node;
	t_chlist	*temp;

	if (a == NULL || *a == NULL)
		return ;
	node = *a;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*a = NULL;
	return ;
}

void	free_checker_list(t_chlist **checker_list)
{
	t_chlist	*node;
	t_chlist	*temp;

	if (checker_list == NULL || *checker_list == NULL)
		return ;
	node = *checker_list;
	while (node)
	{
		temp = node->next;
		free(node->move);
		free(node);
		node = temp;
	}
	*checker_list = NULL;
	return ;
}

void	free_all(t_chlist **a, t_chlist **b, t_chlist **checker_list)
{
	free_list(a);
	free_list(b);
	free_checker_list(checker_list);
	exit(EXIT_FAILURE);
}
