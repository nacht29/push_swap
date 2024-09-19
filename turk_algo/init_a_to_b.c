#include "../includes/push_swap.h"

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
	cost_calc(stack_a, stack_b);
	set_cheapest(stack_a);
}

/*
*sets the target nodes for nodes in stack A
(the approx pos nodes A will be pushed to in B)
*it finds the node in B that's the closest and at the same time
smaller than node in A
*stack B is sorted in descending order
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
		cur_a = cur_a->next;
	}
}
/*
*brings node in A and its target node above median
*does not perform rotations if the first node is alr in the 
correct pos
*accounts for
*/
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
	bring_to_top(*stack_a, cheapest, 'a');
	bring_to_top(*stack_b, cheapest->target_node, 'b');
	push_a_to_b(stack_a, stack_b);
}
