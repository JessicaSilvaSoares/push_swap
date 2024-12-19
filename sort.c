/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:33:07 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/18 18:33:09 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **lst_a, t_list **lst_b);
void	sort_small(t_list **lst_a, t_list **lst_b);
void	sort(t_list **lst_a, t_list **lst_b);
void	reverse_list(t_list **lst_a, t_list **lst_b);
void	push_min_b(t_list **lst_a, t_list **lst_b);


void	sort_list(t_list **lst_a)
{
	size_t	len;
	t_list	*lst_b;

	len = ft_lstsize(*lst_a);
	if (len < 2)
		return ;
	if (check_order(*lst_a, 0))
		return ;
	if (len == 2)
	{
		swap(lst_a, &lst_b, 0);
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
	push_min_b(lst_a, lst_b);
	swap(lst_a, lst_b, 0);
	push(lst_a, lst_b, 0);
}

void	sort_small(t_list **lst_a, t_list **lst_b)
{
	push_min_b(lst_a, lst_b);
	push_min_b(lst_a, lst_b);
	if (ft_lstsize(*lst_a) == 2)
		swap(lst_a, lst_b, STACK_A);
	else
		sort3(lst_a, lst_b);
	while (ft_lstsize(*lst_b))
		push(lst_a, lst_b, STACK_A);
}

void	push_min_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *lst_a;
	min = *lst_a;
	while (tmp)
	{
		if (*(int *)min->content > *(int *)tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	while ((*lst_a)->next)
	{
		if ((*lst_a) == min)
		{
			push(lst_a, lst_b, STACK_B);
			break ;
		}
		else
			rotate(lst_a, lst_b, STACK_A);
	}
}

void	sort(t_list **lst_a, t_list **lst_b)
{
	lst_a = lst_b;
}

void	reverse_list(t_list **lst_a, t_list **lst_b)
{
	while (ft_lstsize(*lst_a) > 2)
	{
		reverse(lst_a, lst_b, STACK_A);
		push(lst_a, lst_b, STACK_B);
	}
	swap(lst_a, lst_b, STACK_A);
	while (ft_lstsize(*lst_b) > 0)
		push(lst_a, lst_b, STACK_A);
}
