/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:19:11 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/02 17:32:43 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "lib/libft.h"

# ifndef MIN_INT
#  define MIN_INT -2147483647
# endif

# ifndef MAX_INT
#  define MAX_INT 2147483648
# endif

void	swap(t_list **lst);
void	push(t_list **a, t_list **b);
void	reverse(t_list **lst);
void	rotate(t_list **lst);
void	putlst(t_list *lst);
void	*lstclear(t_list **lst);
t_list	*create_list(char **matriz);
int		*create_content(char *s);
int		check_only_digits(char **matriz);

#endif
