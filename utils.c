/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:19:18 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/04 18:34:56 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(char **matriz)
{
	int		i;
	int		*content;
	t_list	*lst;
	t_list	*new;

	if (!matriz || !check_only_digits(matriz))
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

	if (!s || !*s)
		return (NULL);
	content = malloc(sizeof(long));
	if (!content)
		return (NULL);
	*content = ft_atol(s);
	if ((*content < MIN_INT || *content > MAX_INT)
		|| (!*content && ft_strncmp(s, "0", 2)))
	{
		free(content);
		return (NULL);
	}
	return ((int *)content);
}

int	check_duplicates(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(int *)lst->content == *(int *)tmp->content)
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
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
			if ((matriz[i][j] == '-' || matriz[i][j] == '+')
				&& (j > 0 && !ft_isspace(matriz[i][j - 1])))
				return (0);
			else if (!ft_isdigit(matriz[i][j])
				&& matriz[i][j] != '-' && matriz[i][j] != '+')
				return (0);
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
		ft_printf("%d, ", *(int *)lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}
