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

void	print_operation(unsigned int operation, unsigned int stack)
{
	const char	***opt = {{"sa", "sb", "ss"}, {"pa", "pb"},
	{"ra", "rb", "rr"}, {"rra", "rrb", "rrr"}};

	ft_printf("%s\n", opt[operation][stack]);
}

void	swap(t_list **lst_a, t_list **lst_b, int stack)
{
	if (stack > 2)
		return ;
	if (stack == STACK_AB && !(ft_lstsize(*lst_a) > 1
			&& ft_lstsize(*lst_b) > 1))
		return ;
	if (*lst_a && (stack == STACK_A || stack == STACK_AB))
		ft_lstswap(lst_a);
	if (*lst_b && (stack == STACK_B || stack == STACK_AB))
		ft_lstswap(lst_b);
	print_operation(OP_SWAP, stack);
}

void	push(t_list **a, t_list **b, unsigned int stack)
{
	t_list	*tmp;

	if (stack > 1)
		return ;
	if (stack == STACK_A)
	{
		if (!a || !*b)
			return ;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*a);
		*a = tmp;
	}
	else if (stack == STACK_B)
	{
		if (!*a || !b)
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*b);
		*b = tmp;
	}
	print_operation(OP_SWAP, stack);
}

void	reverse(t_list **lst_a, t_list **b, unsigned int stack)
{
	if (stack > 2)
		return ;
	if (stack == STACK_AB && !(ft_lstsize(*lst_a) > 1
			&& ft_lstsize(*lst_b) > 1))
		return ;
	if (ft_lstsize(*lst_a) > 1 && (stack == STACK_A || stack == STACK_AB))
		rev_list(lst_a);
	if (ft_lstsize(*lst_b) > 1 && (stack == STACK_B || stack == STACK_AB))
		rev_list(lst_b);
	print_operation(OP_REVERSE, stack);
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

void	rotate(t_list **lst_a, t_list **lst_b, unsigned int stack)
{
	if (stack > 2)
		break ;
	if (stack == STACK_AB && !(ft_lstsize(*lst_a) > 1
			&& ft_lstsize(*lst_b) > 1))
		return ;
	if (ft_lstsize(*lst_a) > 1 && (stack == STACK_A || stack == STACK_AB))
		rot_list(lst_a);
	if (ft_lstsize(*lst_b) > 1 && (stack == STACK_A || stack == STACK_AB))
		rot_list(lst_b);
	print_operation(OP_ROTATE, stack);
}

void	rot_list(t_list **lst)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	last->next = *lst;
	*lst = (*lst)->next;
	(last->next)->next = NULL;
}
