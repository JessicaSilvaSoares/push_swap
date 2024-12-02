#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "lib/libft.h"

void	push(t_list **a, t_list **b);
void	rotate(t_list **lst);
void	reverse(t_list **lst);
void	putlst(t_list *lst);
t_list	*create_list(char **matriz);
int	verify_matriz(char **matriz);

#endif
