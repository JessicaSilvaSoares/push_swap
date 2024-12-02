#include "push_swap.h"

void	ft_putlst(t_list **lst);

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*new;
	int	i;
	int	*content;

	if (argc < 2)
	{
		ft_printf("\n");
		return (0);
	}
	lst = NULL;
	new = NULL;
	i = 1;
	while (argv[i])
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
		{
			free(content);
			if (lst)
				ft_lstclear(&lst, free);
			return (0);
		}
		*content = ft_atoi(argv[i]);
		new = ft_lstnew((void *)content);
		if (!new)
		{
			free(new);
			ft_lstclear(&lst, free);
		}
		ft_lstadd_back(&lst, new);
		i++;
	}

	/* SWAP *//*
	ft_printf("swap\n");
	ft_printf("before\n");
	ft_putlst(&lst);
	ft_lstswap(&lst);
	ft_printf("\nafter\n");
	ft_putlst(&lst);*/

	/* PUSH *//*
	ft_printf("\npush\n");
	ft_printf("before a\n");
	ft_putlst(&a);
	ft_printf("\nbefore b\n");
	ft_putlst(&lst);
	push(&a, &lst);
	ft_printf("\n\n after a\n");
	ft_putlst(&a);
	ft_printf("\nafter b\n");
	ft_putlst(&lst);*/


	/* ROTATE *//*
	ft_printf("\nrotate\n");
	ft_printf("before\n");
	ft_putlst(&lst);
	rotate(&lst);
	ft_printf("\nafter\n");
	ft_putlst(&lst);*/


	/* REVERSE *//*
	ft_printf("\nreverse\n");
	ft_printf("before\n");
	ft_putlst(&lst);
	reverse(&lst);
	ft_printf("\nafter\n");
	ft_putlst(&lst);

	ft_lstclear(&lst, free);
	ft_lstclear(&a, free); */
	return (0);
}

void	ft_putlst(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while(tmp)
	{
		ft_printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
}
