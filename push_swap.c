/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:19:06 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/04 18:12:14 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(char **matriz);
char	*ft_join(char *s1, char const *s2);
void	*free_matriz(char **matriz);
void	sort_list(t_list **lst_a);

int	main(int argc, char **argv)
{
	char	**matriz;
	char	*tmp;
	t_list	*lst;

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
	sort_list(&lst);
	if (!check_order(lst, 0))
		ft_printf("Error\n");
	//putlst(lst);
	ft_lstclear(&lst, free);
	return (0);
}

int	check_order(t_list *lst, int rev)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		if (!rev && *(int *)lst->content > *(int *)tmp->content)
			return (0);
		if (rev && *(int *)lst->content < *(int *)tmp->content)
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
	int		i;

	if (!args || !*args)
		return (NULL);
	str = ft_strdup(args[0]);
	i = 1;
	while (args[i])
	{
		str = ft_join(str, args[i]);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}

char	*ft_join(char *s1, char const *s2)
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
	free(s1);
	return (str);
}
