#include "../includes/push_swap.h"

/*
ref:

void	init_nodes_a(stack *stack_a, stack *stack_b)
{
	above_median(stack_a); - init_move utils
	set_target_a(stack_a, stack_b); - init nodes
	cost_calc(stack_a); - init move utils
	set_cheapest(stack_a); init move utils
}
*/

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
	}
	cur_a = cur_a->next;
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
		cur_b = cur_b->next;
	}
}
