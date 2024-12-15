#include "push_swap.h"

void	sort_list(t_list **lst_a)
{
	size_t	len;
	t_list	*lst_b;
	t_list	*tmp;

	len = ft_lstsize(*lst_a);
	if (len < 2)
		return ;
	if (check_order(*lst_a, 0))
		return ;
	if (len == 2)
	{
		tmp = (*lst_a)->next;
		swap(lst_a);
		ft_printf("sa\n");
		return ;
	}
	lst_b = NULL;
	if (check_order(*lst_a, 1))
		reverse_list(lst_a, &lst_b);
}

void	reverse_list(t_list **lst_a, t_list **lst_b)
{
	while (ft_lstsize(*lst_a) > 2)
	{
		reverse(lst_a);
		ft_printf("rra\n");
		push(lst_a, lst_b);
		ft_printf("pb\n");
	}
	swap(lst_a);
	ft_printf("sa");
	while (ft_lstsize(*lst_b) > 0)
	{
		push(lst_b, lst_a);
		ft_printf("pa\n");
	}
}
