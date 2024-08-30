#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	stack	*stack_a;
	stack	*stack_b;

	if (ac < 3)
		quit();
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < ac)
	{
		if (is_num_str(av[i]) == FALSE && is_sign(av[i][0]) == FALSE)
			quit();
		add_to_bottom(stack_a, create_new_node(ft_atoi(av[i])));
		i++;
	}
}

/*
*stack A and B each contains a linked list, aka the node struct
*maybe create a function to move things into both nodes
*/