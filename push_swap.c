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
	putlst(lst);
	return (0);
}
