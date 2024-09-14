#include "../includes/push_swap.h"

/*
*malloc and create a new node
*/
node	*append_node(int new_num)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->num = new_num;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = FALSE;
	new_node->cheapest = FALSE;
	new_node->target_node = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*
*adds a new node to the start of a linked list
*/
void	add_to_top(stack *stack, node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
}

/*
*adds a new node to the end of a linked list
*/
void 	add_to_bottom(stack *stack, node *new_node)
{
	node	*current;

	if (!stack || !new_node)
		return;
	if (!stack->top)
	{
		stack->top = new_node;
		return;
	}
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

/*
*frees the entire stack
*/
void	free_whole_stack(stack **stack)
{
	node	*current;
	node	*temp;

	if (!stack || !(*stack))
		return ;
	current = (*stack)->top;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	(*stack)->top = NULL;
	(*stack)->size = 0;
}
