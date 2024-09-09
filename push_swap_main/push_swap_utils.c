#include "../includes/push_swap.h"

void	err_and_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	show_content(char *name, stack *stack)
{
	node	*cur;
	int		size;

	ft_printf("name: %s\n", name);
	if (!(stack))
	{
		ft_printf("size: 0\n");
		return ;
	}
	cur = stack->top;
	size = 1;
	/*
	while (cur)
	{
		ft_printf("node: %i\n", size);
		ft_printf("num: %i\npush cost: %i\nabove median: %i\ncheapest: %i\n", cur->num, cur->push_cost, cur->above_median, cur->cheapest);
		ft_printf("size: %i\n", stack->size);
		ft_printf("\n");
		size++;
		cur = cur->next;
	}
	*/
	while (cur)
	{
		ft_printf("num: %i\n", cur->num);
		cur = cur->next;
	}
}

/*
// testing operations

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
	// rotate_a(&stack_a);
	// rotate_a(&stack_a);
	init_stack_b(&stack_b);
	push_a_to_b(&stack_a, &stack_b);
	push_a_to_b(&stack_a, &stack_b);
	push_a_to_b(&stack_a, &stack_b);
	reverse_rotate_b(&stack_b);
	push_b_to_a(&stack_b, &stack_a);
	reverse_rotate_b(&stack_b);
	push_b_to_a(&stack_b, &stack_a);
	reverse_rotate_b(&stack_b);
	push_b_to_a(&stack_b, &stack_a);
	show_content("stack A", stack_a);
	show_content("stack B", stack_b);
}
*/