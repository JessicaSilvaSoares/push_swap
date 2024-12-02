/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:19:06 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/02 20:19:08 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(char **matriz);
char	*ft_join(char const *s1, char const *s2);
void	*free_matriz(char **matriz);

int	main(int argc, char **argv)
{
	char	**matriz;
	char	*tmp;
	t_list	*lst_a;

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
	lst_a = create_list(matriz);
	matriz = free_matriz(matriz);
	if (!lst_a || !check_duplicates(lst_a))
		ft_printf("Error\n");
	else
		putlst(lst_a);
	// (void *)lst_b;
	ft_lstclear(&lst_a, free);
	return (0);
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
