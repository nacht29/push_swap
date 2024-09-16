#include "../includes/push_swap.h"

/*
*determine if the current node is above or below median line
*used to determine the least costly operation to perform
to bring the node to the correct pos
*/
void	index_median(stack *stack)
{
	node	*cur;
	int		median;
	int		i;

	cur = stack->top;
	median = stack->size / 2;
	i = 0;
	while (cur)
	{
		cur->index = i;
		if (i <= median)
			cur->above_median = TRUE;
		else
			cur->above_median = FALSE;
		cur = cur->next;
		i++;
	}
}
/*
*search for the cheapest node to push
*the default cheapest push cost is INT_MAX
*function iterates through the stack
*the node with the lower push cost than the previous lowest
will temporarily be recorded as cheapest
*finally, the final, cheapest node will have its [cheapest] flag
set to TRUE
*hence, if no node is cheaper than the first, the first node is the
cheapest
*/
void	set_cheapest(stack *stack)
{
	node	*cur;
	node	*cur_cheapest;
	int		cheapest_cost;

	if (!stack)
		return ;
	cur = stack->top;
	cheapest_cost = INT_MAX;
	while (cur)
	{
		if (cur->push_cost < cheapest_cost)
		{
			cheapest_cost = cur->push_cost;
			cur_cheapest = cur;
		}
		cur = cur->next;
	}
	cur_cheapest->cheapest = TRUE;
}

/*
*locates and returns the cheapest node
*searches for node with [cheapest = TRUE]
*/
node	*get_cheapest(stack *stack)
{
	node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->cheapest == TRUE)
			break;
		cur = cur->next;
	}
	return (cur);
}

/*
*calculate the cost of pushing a node from one stack
to the other
*push cost is calculated by the number of steps needed to bring
the push node and its target node to the correct pos
(most likely on top of the stack)
*/
void	cost_calc(stack *stack)
{
	node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->above_median == TRUE)
			cur->push_cost += cur->index;
		if (cur->target_node->above_median == TRUE)
			cur->push_cost += cur->target_node->index;
		cur = cur->next;
	}
}
