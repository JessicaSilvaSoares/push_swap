#include "push_swap.h"

void	ft_putlst(t_list **lst);

int	main(void)
{
	t_list	*a;
	t_list	*lst;
	int	*i;

	i = malloc(sizeof(int));
	*i = 4;
	lst = ft_lstnew(i);
	i = malloc(sizeof(int));
	*i = 8;
	lst->next = ft_lstnew(i);
	/* SWAP
	ft_printf("before\n");
	ft_putlst(&lst);
	ft_lstswap(&lst);
	ft_printf("\nafter\n");
	ft_putlst(&lst);*/

	/* PUSH
	ft_printf("before a\n");
	ft_putlst(&a);
	ft_printf("\nbefore b\n");
	ft_putlst(&lst);
	push(&a, &lst);
	ft_printf("\n\n after a\n");
	ft_putlst(&a);
	ft_printf("\nafter b\n");
	ft_putlst(&lst);
	*/

	return (0);
}

void	ft_putlst(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while(tmp)
	{
		ft_printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
}
