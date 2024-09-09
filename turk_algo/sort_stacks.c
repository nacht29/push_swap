#include "../includes/push_swap.h"

void	sort_stacks(stack **stack_a, stack **stack_b)
{
	init_stack_b(stack_b);
	if ((*stack_a)->size > 3)
		push_a_to_b(stack_a, stack_b);
	if ((*stack_a)->size > 3)
		push_a_to_b(stack_a, stack_b);
	while ((*stack_a)->size > 3)
	{
		push_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
}

void	move_a_to_b(stack **stack_a, stack **stack_b)
{
	return ;
}
