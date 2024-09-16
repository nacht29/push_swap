#include "../includes/push_swap.h"

void	init_nodes_b(stack *stack_a, stack *stack_b)
{
	index_median(stack_b);
}

/*
*sets the target nodes for nodes in stack B
(the approx pos nodes B will be pushed to in A)
*it finds the node in A that's the closest and at the same time
larger than node in B
*stack A is sorted in ascending order
*/
void	set_target_b(stack *stack_a, stack *stack_b)
{
	node	*cur_a;
	node	*cur_b;
	int		closest_larger;

	cur_b = stack_b->top;
	while (cur_b)
	{
		cur_a = stack_a->top;
		closest_larger = INT_MAX;
		while (cur_a)
		{
			if (cur_a->num > cur_b->num && cur_a->num < closest_larger)
			{
				closest_larger = cur_a->num;
				cur_b->target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (closest_larger = INT_MAX)
				cur_b->target_node = find_min(stack_a);
		cur_b = cur_b->next;
	}
}
