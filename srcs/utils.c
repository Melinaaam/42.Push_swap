#include "libft.h"
#include "push_swap.h"

void lstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void lstclear(t_pslist **lst, void (*del)(void*))
{
	t_pslist	*temp;
	t_pslist	*temp2;

	if (!lst)
		return;
	temp = *lst;
	while (temp)
	{
		temp2 = temp->next;
			del(temp->content);
		free(temp);
		temp = temp2;
	}
	*lst = NULL;
}
