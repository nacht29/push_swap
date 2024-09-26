#include "../includes/push_swap.h"

void	init_stack_a(int ac, char **av, stack **stack_a)
{
	*stack_a = (stack *)malloc(sizeof(stack));
	if (!(*stack_a) || !stack_a)
		err_and_exit();
	(*stack_a)->top = NULL;
	(*stack_a)->size = 0;
	parse_stack_a(ac, av, stack_a);
}

void	parse_stack_a(int ac, char **av, stack **stack_a)
{
	int		i;
	node	*new_node;
	char	*num_str;
	char	**num_str_arr;

	num_str = combine_str(ac, av);
	num_str_arr = ft_split(num_str, ' ');
	i = 0;
	while (num_str_arr[i])
	{
		if (parse_check(num_str_arr[i], (*stack_a)) == FALSE)
			free_parse_data(stack_a, &num_str_arr, &num_str);
		new_node = append_node(ft_atoi(num_str_arr[i]));
		if (!new_node)
			err_and_exit();
		add_to_bottom((*stack_a), new_node);
		(*stack_a)->size++;
		i++;
	}
	free(num_str);
	free_str_arr(&num_str_arr);
}

void	err_and_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_str_arr(char ***str_arr)
{
	int	i;

	i = 0;
	while ((*str_arr)[i])
	{
		free((*str_arr)[i]);
		i++;
	}
	free(*str_arr);
}
