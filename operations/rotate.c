#include "../includes/push_swap.h"

/*
*Shift up all elements of stack A by 1.
The first element becomes the last one.
*
*As seem, stack->top is replaced by stack->top-next
1st node is replaced by 2nd node
nodes are shifted up
*
*Steps:
*1.Remove the first node: Detach the first node from the list.
*2.Traverse to the last node: Find the last node in the list.
*3.Attach the first node after the last node: 
Make the previously first node the new last node.
*4.Update the head of the list: Set the second node as the new 
head of the list.
*/
void	rotate_a(stack **stack_a)
{
	node	*first_node;
	// node	*current;

	if ((*stack_a)->size <= 1)
		return ;
	first_node = (*stack_a)->top;
	(*stack_a)->top = (*stack_a)->top->next;
	// current = (*stack_a)->top;
	first_node->next = NULL;
	add_to_bottom(*stack_a, first_node);
	ft_printf("ra\n");
}

/*
*Shift up all elements of stack B by 1.
The first element becomes the last one.
*
*As seem, stack->top is replaced by stack->top-next
1st node is replaced by 2nd node
nodes are shifted up
*
*Steps:
*1.Remove the first node: Detach the first node from the list.
*2.Traverse to the last node: Find the last node in the list.
*3.Attach the first node after the last node: 
Make the previously first node the new last node.
*4.Update the head of the list: Set the second node as the new 
head of the list.
*/
void	rotate_b(stack **stack_b)
{
	node	*first_node;
	// node	*current;

	if ((*stack_b)->size <= 1)
		return ;
	first_node = (*stack_b)->top;
	(*stack_b)->top = (*stack_b)->top->next;
	// current = (*stack_b)->top;
	first_node->next = NULL;
	add_to_bottom(*stack_b, first_node);
	ft_printf("rb\n");
}

/*
*reverse rotates stacks A and B
*/
void	rotate_all(stack **stack_a, stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}