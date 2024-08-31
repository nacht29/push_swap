#include "../includes/push_swap.h"

void	check_push(stack *stack_a, stack *stack_b);
void	check(stack *stack);

int main(int ac, char *av[])
{
	stack	*stack_a;
	stack	*stack_b;
	
	if (ac < 2)
		quit();
	init_stack(&stack_a, &stack_b);
	add_num_to_stack_a(ac, av, &stack_a);
	// check_push(stack_a, stack_b);
	check(stack_a);
}

void	init_stack(stack **stack_a, stack **stack_b)
{
	*stack_a = (stack *)malloc(sizeof(stack));
	if (!(*stack_a) || !stack_a)
		quit();
	(*stack_a)->top = NULL;
	(*stack_a)->size = 0;
	*stack_b = (stack *)malloc(sizeof(stack));
	if (!(*stack_b) || !stack_b)
		quit();
	(*stack_b)->top = NULL;
	(*stack_b)->size = 0;
}

void	add_num_to_stack_a(int ac, char **av, stack **stack_a)
{
	int		i;
	node	*new_node;

	i = 1;
	while (i < ac)
	{
		if (is_num_str(av[i]) == FALSE)
			quit();
		new_node = create_new_node(ft_atoi(av[i]));
		if (!new_node)
			quit();
		add_to_bottom((*stack_a), new_node);
		(*stack_a)->size++;
		i++;
	}
}
