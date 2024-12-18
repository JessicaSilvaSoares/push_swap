/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:51:28 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/02 17:51:29 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_list(t_list **lst);

void	print_operation(int operation, int stack_a, int stack_b);
void	rev_list(t_list **lst);
int		cmp_swap(t_list **lst);

void	swap(t_list **lst_a, t_list **lst_b, int stack)
{
	int		count_a;
	int		count_b;

	if (stack > STACK_AB)
		return ;
	if (stack == STACK_AB && !(ft_lstsize(*lst_a) > 1
			&& ft_lstsize(*lst_b) > 1))
		return ;
	count_a = 0;
	count_b = 0;
	if ((stack == STACK_A || stack == STACK_AB) && cmp_swap(lst_a)
		&& ft_lstsize(*lst_a) > 1)
	{
		ft_lstswap(lst_a);
		count_a++;
	}

	if ((stack == STACK_B || stack == STACK_AB) && cmp_swap(lst_b)
		&& ft_lstsize(*lst_b) > 1)
	{
		ft_lstswap(lst_b);
		count_b++;
	}

	print_operation(OP_SWAP, count_a, count_b);
}

int	cmp_swap(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return (0);
	tmp = (*lst)->next;
	if (*(int *)(*lst)->content <= *(int *)tmp->content)
		return (0);
	return (1);
}

void	push(t_list **a, t_list **b, int stack)
{
	t_list	*tmp;
	int		count_a;
	int		count_b;

	if (stack > STACK_B)
		return ;
	count_a = 0;
	count_b = 0;
	if (stack == STACK_A)
	{
		if (!a || !*b)
			return ;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*a);
		*a = tmp;
		count_a++;
	}
	else if (stack == STACK_B)
	{
		if (!*a || !b)
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*b);
		*b = tmp;
		count_b++;
	}
	print_operation(OP_PUSH, count_a, count_b);
}

void	reverse(t_list **lst_a, t_list **lst_b, int stack)
{
	int		count_a;
	int		count_b;

	if (stack > STACK_AB)
		return ;
	if (stack == STACK_AB && !(ft_lstsize(*lst_a) > 1
			&& ft_lstsize(*lst_b) > 1))
		return ;
	count_a = 0;
	count_b = 0;
	if ((stack == STACK_A || stack == STACK_AB) && ft_lstsize(*lst_a) > 1)
	{
		rev_list(lst_a);
		count_a++;
	}
	if ((stack == STACK_B || stack == STACK_AB) && ft_lstsize(*lst_b) > 1)
	{
		rev_list(lst_b);
		count_b++;
	}
	print_operation(OP_REVERSE, count_a, count_b);
}

void	rev_list(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;

	last = ft_lstlast(*lst);
	last->next = *lst;
	*lst = last;
	tmp = *lst;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	rotate(t_list **lst_a, t_list **lst_b, int stack)
{
	int		count_a;
	int		count_b;

	if (stack > STACK_AB)
		return ;
	if (stack == STACK_AB && !(ft_lstsize(*lst_a) > 1
			&& ft_lstsize(*lst_b) > 1))
		return ;
	count_a = 0;
	count_b = 0;
	if ((stack == STACK_A || stack == STACK_AB) && ft_lstsize(*lst_a) > 1)
	{
		rot_list(lst_a);
		count_a++;
	}
	if ((stack == STACK_B || stack == STACK_AB) && ft_lstsize(*lst_b) > 1)
	{
		rot_list(lst_b);
		count_b++;
	}
	print_operation(OP_ROTATE, count_a, count_b);
}

void	rot_list(t_list **lst)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	last->next = *lst;
	*lst = (*lst)->next;
	(last->next)->next = NULL;
}

void	print_operation(int operation, int stack_a, int stack_b)
{
	const char	*opt[4][3] = {{"sa", "sb", "ss"}, {"pa", "pb"},
	{"ra", "rb", "rr"}, {"rra", "rrb", "rrr"}};

	if (stack_a && stack_b)
		ft_printf("%s\n", opt[operation][STACK_AB]);
	else if (stack_a)
		ft_printf("%s\n", opt[operation][STACK_A]);
	else if (stack_b)
		ft_printf("%s\n", opt[operation][STACK_B]);
}