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
# ifndef STACK_A
#  define STACK_A 0
# endif
# ifndef STACK_B
#  define STACK_B 1
# endif
# ifndef STACK_AB
#  define STACK_AB 2
# endif
# ifndef OP_SWAP
#  define OP_SWAP 0
# endif
# ifndef OP_PUSH
#  define OP_PUSH 1
# endif
# ifndef OP_ROTATE
#  define OP_ROTATE 2
# endif
# ifndef OP_REVERSE
#  define OP_REVERSE 3
# endif

void	swap(t_list **lst_a, t_list **lst_b, int stack);
void	push(t_list **lst_a, t_list **lst_b, int stack);
void	reverse(t_list **lst_a, t_list **lst_b, int stack);
void	rotate(t_list **lst_a, t_list **lst_b, int stack);
void	putlst(t_list *lst);
void	*lstclear(t_list **lst);
t_list	*create_list(char **matriz);
int		*create_content(char *s);
int		check_only_digits(char **matriz);
int		check_duplicates(t_list *lst);
int		check_order(t_list *lst, int rev);
void	reverse_list(t_list **lst_a, t_list **lst_b);

#endif
