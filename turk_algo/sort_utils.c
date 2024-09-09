#include "../includes/push_swap.h"

/*
*finds the index of a particular node in a linked list
*the node is identified by its number
*used to determine if the node is above median line
*/
int	get_index(stack *stack, int num_in_stack)
{
	int		index;
	node	*cur;

	cur = stack->top;
	index = 0;
	while (cur && cur->num != num_in_stack)
	{
		index++;
		cur = cur->next;
	}
	return (index);
}

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
