#include "../includes/push_swap.h"

static char	*combine_str(int ac, char **av);

int main(int ac, char *av[])
{
	stack	*stack_a;
	stack	*stack_b;
	
	if (ac < 2)
		err_and_exit();
	init_stack(&stack_a, &stack_b);
	parse_stack_a(ac, av, &stack_a);
	check(stack_a);
	push_swap(stack_a, stack_b);
}

void	init_stack(stack **stack_a, stack **stack_b)
{
	*stack_a = (stack *)malloc(sizeof(stack));
	if (!(*stack_a) || !stack_a)
		err_and_exit();
	(*stack_a)->top = NULL;
	(*stack_a)->size = 0;
	*stack_b = (stack *)malloc(sizeof(stack));
	if (!(*stack_b) || !stack_b)
		err_and_exit();
	(*stack_b)->top = NULL;
	(*stack_b)->size = 0;
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
		new_node = create_new_node(ft_atoi(num_str_arr[i]));
		if (!new_node)
			err_and_exit();
		add_to_bottom((*stack_a), new_node);
		(*stack_a)->size++;
		i++;
	}
}

static char	*combine_str(int ac, char **av)
{
	int		i;
	char	*line;
	char	*temp;
	char	*with_spc;

	i = 1;
	line = ft_strdup("");
	while (i < ac)
	{
		with_spc = ft_strjoin(" ", av[i]);
		temp = ft_strjoin(line, with_spc);
		free(line);
		free(with_spc);
		line = temp;
		i++;
	}
	return (line);
}
