/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:28:09 by jesda-si          #+#    #+#             */
/*   Updated: 2024/09/28 17:00:15 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	int	i;

	if (c > 1)
	{
		while (v[1][i])
			printf("%c => %d\n", v[1][i++], ft_isalpha(v[1][i++]));
	}
	return (0);
}*/