#include "../includes/push_swap.h"

#include "../includes/push_swap.h"

/*
*boolean function
*returns TRUE is stack is sorted, else FALSE
*/
int	stack_is_sorted(stack *stack)
{
	node	*cur;
	cur = stack->top;

	while (cur->next)
	{
		if (cur->num > cur->next->num)
			return (FALSE);
		cur = cur->next;
	}
	return (TRUE);
}

/*
*finds the node containing the maximum value in a stack
*used when nodes in A cannot find target node in B
*/
node	*find_max(stack *stack)
{
	node	*cur;
	int		max;
	node	*max_node;

	cur = stack->top;
	max = INT_MIN;
	max_node = NULL;
	while (cur)
	{
		if (cur->num > max)
		{
			max = cur->num;
			max_node = cur;
		}
		cur = cur->next;
	}
	return (max_node);
}


/*
*finds the node containing the maximum value in a stack
*used when nodes in B cannot find target node in A
*/
node	*find_min(stack *stack)
{
	node	*cur;
	int		min;
	node	*min_node;

	cur = stack->top;
	min = INT_MAX;
	min_node = NULL;
	while (cur)
	{
		if (cur->num < min)
		{
			min = cur->num;
			min_node = cur;
		}
		cur = cur->next;
	}
	return (min_node);
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
