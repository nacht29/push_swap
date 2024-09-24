#include "../includes/push_swap.h"

/*
*sorts > 3
*initiates stack B for use
*already checked, no need to run index_median here
*/
void	sort_stacks(stack **stack_a, stack **stack_b)
{
	init_stack_b(stack_b);
	if (stack_is_sorted(*stack_a) == TRUE)
		return ;
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
	while ((*stack_b)->top)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	min_on_top(*stack_a);
}

/*
*for sorting > 3
*mallocs and initiates stack b
*/
void	init_stack_b(stack **stack_b)
{
	*stack_b = (stack *)malloc(sizeof(stack));
	if (!(*stack_b) || !stack_b)
		err_and_exit();
	(*stack_b)->top = NULL;
	(*stack_b)->size = 0;
}

void	min_on_top(stack *stack_a)
{
	node	*min;
	
	min = find_min(stack_a); 
	while (stack_a->top != min)
	{
		index_median(stack_a);
		if (min->above_median == TRUE)
			rotate_a(&stack_a, TRUE);
		else
			reverse_rotate_a(&stack_a, TRUE);
	}
}
