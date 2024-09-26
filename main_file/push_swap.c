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
	free_whole_stack(&stack_a);
	free(stack_a);
	free_whole_stack(&stack_b);
	free(stack_b);
}
