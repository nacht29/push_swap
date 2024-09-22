#include "../includes/push_swap.h"

int main(int ac, char *av[])
{
	stack	*stack_a;
	stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		err_and_exit();
	else
		init_stack_a(ac, av, &stack_a);
	if (stack_is_sorted(stack_a) == FALSE)
	{
		if (stack_a->size == 2)
			sort_two(&stack_a);
		else if (stack_a->size == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	// show_content("stack_a", stack_a);
	// ft_printf("is sorted: %i\n", stack_is_sorted(stack_a));
}

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
}
