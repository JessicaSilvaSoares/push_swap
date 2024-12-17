#include "push_swap.h"

void	sort3(t_list **lst_a, t_list **lst_b);
void	sort_small(t_list **lst_a, t_list **lst_b);
void	sort(t_list **lst_a, t_list **lst_b);

void	sort2(t_list **lst, int stack)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	if (*(int *)(*lst)->content <= *(int *)tmp->content)
		return ;
	swap(lst, stack);
}

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
		sort2(lst_a, 0);
		return ;
	}
	lst_b = NULL;
	if (check_order(*lst_a, 1))
	{
		reverse_list(lst_a, &lst_b);
		return ;
	}
	if (len == 3)
	{
		sort3(lst_a, &lst_b);
		return ;
	}
	if (len == 4 || len == 5)
	{
		sort_small(lst_a, &lst_b);
		return ;
	}
	sort(lst_a, &lst_b);
}

void	sort3(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	t_list	*min;

	push_min_b(lst_a, lst_b);
	sort2(lst_a, 0);
	push(lst_b, lst_a, 0);
}

void	sort_small(t_list **lst_a, t_list **lst_b)
{
	push_min_b(lst_a, lst_b);
	push_min_b(lst_a, lst_b);
	if (ft_lstsize(*lst_a) == 2)
		swap(lst_a, lst_b, 2);
	else
	{
		sort3(lst_a, lst_b);
		swap(lst_a, lst_b, 1);
	}
	while (ft_lstsize(*lst_b))
		push(lst_a, lst_b, 0);
}

void	push_min_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *lst_a;
	min = tmp;
	while (tmp->next)
	{
		if (*(int *)min->content > *(int *)tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	tmp = *lst_a;
	while (tmp->next)
	{
		tmp = *lst_a;
		if (tmp == min)
		{
			push(lst_a, lst_b, 1);
			break ;
		}
		else
			rotone(lst_a, 0);
	}
}

void	sort_small(t_list **lst_a, t_list **lst_b)
{
}

void	sort(t_list **lst_a, t_list **lst_b)
{
}

// 1 3 2
// 2 1 3
// 2 3 1
// 3 2 1
// 3 1 2

void	reverse_list(t_list **lst_a, t_list **lst_b)
{
	while (ft_lstsize(*lst_a) > 2)
	{
		reverse(lst_a);
		ft_printf("rra\n");
		push(lst_a, lst_b);
		ft_printf("pb\n");
	}
	sort2(lst_a);
	ft_printf("sa");
	while (ft_lstsize(*lst_b) > 0)
	{
		push(lst_b, lst_a);
		ft_printf("pa\n");
	}
}
