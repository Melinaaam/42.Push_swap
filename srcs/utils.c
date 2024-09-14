#include "libft.h"
#include "push_swap.h"

// void lstadd_back(t_pslist **lst, t_pslist *new)
// {
// 	t_pslist	*temp;

// 	if (!*lst)
// 		*lst = new ;
// 	else
// 	{
// 		temp = *lst;
// 		while (temp->next != NULL)
// 			temp = temp->next;
// 		temp->next = new;
// 	}
// 	ft_printf("Ajout de l'element [%d] a la liste \n");
// }

// void lstclear(t_pslist **lst, void (*del)(void*))
// {
// 	t_pslist	*temp;

// 	if (lst)
// 	{
// 		temp = (*lst)->next;
// 		del(((*lst))->content);
// 		free(*lst);
// 		*lst = temp;
// 	}
// }

int	safe_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;

	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		if (neg == 1 && nb > INT_MAX)
			return (-1);
		if (neg == -1 && -nb < INT_MIN)
			return (0);
		i++;
	}
	return ((int)(nb * neg));
}

int	size_stack(t_pslist *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
