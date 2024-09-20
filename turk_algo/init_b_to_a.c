#include "../includes/push_swap.h"

void	init_nodes_b(stack *stack_a, stack *stack_b)
{
	index_median(stack_b);
	set_target_b(stack_a, stack_b);
	// cost_calc(stack_b, stack_a);
	// set_cheapest(stack_b);
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

void	move_b_to_a(stack **stack_a, stack **stack_b)
{
	node	*cheapest;

	cheapest = get_cheapest(*stack_b);
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while ((*stack_b)->top != cheapest)
			rotate_all(stack_a, stack_b);
	}
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
	{
		while ((*stack_b)->top != cheapest)
			reverse_rotate_all(stack_a, stack_b);
	}
	bring_to_top(*stack_b, cheapest, 'b');
	bring_to_top(*stack_a, cheapest->target_node, 'a');
	push_b_to_a(stack_a, stack_b);
}