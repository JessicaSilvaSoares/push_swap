/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:19:06 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/02 17:19:08 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst;

	if (argc < 2)
	{
		ft_printf("\n");
		return (0);
	}
	lst = create_list(&argv[1]);
	if (!lst)
		ft_printf("Error\n");
	else
		putlst(lst);
	return (0);
}
