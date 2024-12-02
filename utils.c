#include "push_swap.h"

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

t_list	*create_list(char **matriz)
{
	int	i;
	int	*content;
	t_list	*lst;
	t_list	*new;

	if (!verify_matriz(matriz))
	{
		ft_printf("Error\n");
		return (NULL);
	}
	lst = NULL;
	new = NULL;
	i = 0;
	while (matriz[i])
	{
		content = malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		*content = ft_atoi(matriz[i]);
		new = ft_lstnew((void *)content);
		if (!new)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	return (lst);
}

int	verify_matriz(char **matriz)
{
	int	i;
	int	j;
	char	*s;

	i = 0;
	while (matriz[i])
	{
		s = matriz[i];
		j = 0;
		while (s[j])
		{
			if (!ft_isdigit(s[j]) && s[j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (matriz[i])
	{
		j = i + 1;
		while (matriz[j])
		{
			if (!ft_strncmp(matriz[i], matriz[j], ft_strlen(matriz[i]) + 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

