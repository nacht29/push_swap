#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	long	*num_arr;
	int		i;
	// stack	*stack_a;
	// stack	*stack_b;

	if (ac < 3)
		quit("Usage: ./push_swap num1 num2 num3 ...");
	i = 1;
	num_arr = malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		if (is_num_str(av[i]) == FALSE && is_sign(av[i][0]) == FALSE)
			quit("Incorrect args");
		num_arr[i] = ft_atol(av[i]);
		i++;
	}
}

/*
*stack A and B each contains a linked list, aka the node struct
*maybe create a function to move things into both nodes
*/