#include "../includes/push_swap.h"

/*
*sorts > 3
*initiates stack B for use
*/
void	sort_stacks(stack **stack_a, stack **stack_b)
{
	init_stack_b(stack_b);
	if ((*stack_a)->size > 3)
		push_a_to_b(stack_a, stack_b);
	if ((*stack_a)->size > 3)
		push_a_to_b(stack_a, stack_b);
	while ((*stack_a)->size > 3 && stack_is_sorted(*stack_a) == FALSE)
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		// init_nodes_b(*stack_a, *stack_b);
		// move_b_to_a(stack_a, stack_b);
		break ;
	}
}

/*
*sets the remaining values in each node in A
*sets:
-median
-target node
-push cost
*prepare to push to B
*/
void	init_nodes_a(stack *stack_a, stack *stack_b)
{
	index_median(stack_a);
	set_target_a(stack_a, stack_b);
	// cost_calc(stack_a);
	set_cheapest(stack_a);
}

void	move_a_to_b(stack **stack_a, stack **stack_b)
{
	node	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while ((*stack_a)->top != cheapest)
			rotate_all(stack_a, stack_b);
	}
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
	{
		while ((*stack_a)->top != cheapest)
			reverse_rotate_all(stack_a, stack_b);
	}
}

void	move_b_to_a(stack **stack_a, stack **stack_b)
{
	push_b_to_a(stack_b, stack_a);
	return ;
}