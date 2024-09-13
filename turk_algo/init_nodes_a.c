#include "../includes/push_swap.h"

/*
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

/*
*sets the target nodes for nodes in stack A
(the approx pos A will be pushed to)
*it finds the node in B that's the closest and at the same time
smaller than node in A
*/
void	set_target_a(stack *stack_a, stack *stack_b)
{
	node	*cur_a;
	node	*cur_b;
	int		closest_smaller;

	cur_a = stack_a->top;
	while (cur_a)
	{
		cur_b = stack_b->top;
		closest_smaller = INT_MIN;
		while (cur_b)
		{
			if (cur_b->num < cur_a->num && cur_b->num > closest_smaller)
			{
				closest_smaller = cur_b->num;
				cur_a->target_node = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (closest_smaller = INT_MIN)
			cur_a->target_node = find_max(stack_b);
	}
	cur_a = cur_a->next;
}
