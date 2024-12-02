#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*a);
	*a = tmp;
}
