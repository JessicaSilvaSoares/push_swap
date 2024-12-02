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

void	swap(t_list **lst)
{
	ft_lstswap(lst);
}

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*a);
	*a = tmp;
}

void	reverse(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;
	size_t	len;

	len = ft_lstsize(*lst);
	if (len < 2)
		return ;
	last = ft_lstlast(*lst);
	last->next = *lst;
	*lst = last;
	tmp = *lst;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	rotate(t_list **lst)
{
	t_list	*last;

	if (!*lst && !(*lst)->next)
		return ;
	last = ft_lstlast(*lst);
	last->next = *lst;
	*lst = (*lst)->next;
	(last->next)->next = NULL;
}
