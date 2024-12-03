/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:19:06 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/03 18:18:20 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(char **matriz);
char	*ft_join(char const *s1, char const *s2);
void	*free_matriz(char **matriz);
void	sort_list(t_list **lst_a);
int     check_order(t_list *lst);

int	main(int argc, char **argv)
{
	char	**matriz;
	char	*tmp;
	t_list	*lst;
	size_t	len;

	//t_list	*lst_b;
	if (argc < 2)
	{
		ft_printf("\n");
		return (0);
	}
	tmp = join_args(&argv[1]);
	matriz = ft_split(tmp, ' ');
	free(tmp);
	if (!matriz)
		return (0);
	lst = create_list(matriz);
	matriz = free_matriz(matriz);
	if (!lst || !check_duplicates(lst))
	{
		ft_printf("Error\n");
		return (0);
	}
	len = ft_lstsize(lst);
	putlst(lst);
	ft_printf("|\n|\n");
	sort_list(&lst);
	putlst(lst);
	ft_lstclear(&lst, free);
	return (0);
}

void	sort_list(t_list **lst_a)
{
	size_t	len;
	//t_list	*lst_b;
	t_list	*tmp;

	len = ft_lstsize(*lst_a);
	if (len < 2)
		return ;
	if (check_order(*lst_a))
		return ;

	if (len == 2)
	{
		tmp = (*lst_a)->next;
		if (*(int *)(*lst_a)->content > *(int *)tmp->content)
		{
			swap(lst_a);
			ft_printf("sa\n");
			return ;
		}
	}
}

int	check_order(t_list *lst)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		if (*(int *)lst->content > *(int *)tmp->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	*free_matriz(char **matriz)
{
	int	i;

	i = -1;
	while (matriz[++i])
	{
		free(matriz[i]);
	}
	free(matriz);
	return (NULL);
}

char	*join_args(char **args)
{
	char	*str;
	char	*tmp;
	int		i;

	if (!args || !*args)
		return (NULL);
	str = ft_strdup(args[0]);
	tmp = NULL;
	i = 1;
	while (args[i])
	{
		tmp = ft_join(str, args[i]);
		if (!tmp)
			return (NULL);
		free(str);
		str = tmp;
		i++;
	}
	return (str);
}

char	*ft_join(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	len = 2;
	len += (int)ft_strlen(s1);
	len += (int)ft_strlen(s2);
	str = (char *)ft_calloc(sizeof (char), len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len);
	ft_strlcat(str, " ", len);
	ft_strlcat(str, s2, len);
	return (str);
}
