/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:19:18 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/02 17:37:53 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(char **matriz)
{
	int		i;
	int		*content;
	t_list	*lst;
	t_list	*new;

	if (!check_only_digits(matriz))
		return (NULL);
	lst = NULL;
	new = NULL;
	i = -1;
	while (matriz[++i])
	{
		content = create_content(matriz[i]);
		if (!content)
			return (lstclear(&lst));
		new = ft_lstnew((void *)content);
		if (!new)
			return (lstclear(&lst));
		ft_lstadd_back(&lst, new);
	}
	return (lst);
}

int	*create_content(char *s)
{
	long	*content;

	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = ft_atol(s);
	if (*content < MIN_INT || *content > MAX_INT)
	{
		free(content);
		return (NULL);
	}
	return ((int *)content);
}

int	check_only_digits(char **matriz)
{
	int		i;
	int		j;

	i = -1;
	while (matriz[++i])
	{
		j = -1;
		while (matriz[i][++j])
		{
			if (!ft_isdigit(matriz[i][j]) && matriz[i][j] != '-')
				return (0);
		}
	}
	i = -1;
	while (matriz[++i])
	{
		j = i + 1;
		while (matriz[j])
		{
			if (!ft_strncmp(matriz[i], matriz[j], ft_strlen(matriz[i]) + 1))
				return (0);
			j++;
		}
	}
	return (1);
}

void	*lstclear(t_list **lst)
{
	ft_lstclear(lst, free);
	return (NULL);
}

void	putlst(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}
