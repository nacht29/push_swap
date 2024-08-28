#include "../includes/push_swap.h"

/*
*Shift down all elements of stack A by 1.
The last element becomes the first one.
*
*Steps:
*1.Remove the first node: Detach the first node from the list.
*2.Traverse to the last node: Find the last node in the list.
*3.Attach the first node after the last node: 
Make the previously first node the new last node.
*4.Update the head of the list: Set the second node as the new 
head of the list.
*/
void	reverse_rotate_stack_a(stack *stack_a)
{
	node	*first_node;
	node	*current;

	first_node = stack_a->top;
	stack_a->top = stack_a->top->next;
	current = stack_a->top;
	first_node->next = NULL;
	add_to_bottom(stack_a, first_node, 0);
	ft_printf("rra\n");
}

/*
*Shift down all elements of stack B by 1.
The last element becomes the first one.
*
*Steps:
*1.Remove the first node: Detach the first node from the list.
*2.Traverse to the last node: Find the last node in the list.
*3.Attach the first node after the last node: 
Make the previously first node the new last node.
*4.Update the head of the list: Set the second node as the new 
head of the list.
*/
void	reverse_rotate_stack_b(stack *stack_b)
{
	node	*first_node;
	node	*current;

	first_node = stack_b->top;
	stack_b->top = stack_b->top->next;
	current = stack_b->top;
	first_node->next = NULL;
	add_to_bottom(stack_b, first_node, 0);
	ft_printf("rrb\n");
}

/*
*reverse rotates A and B
*/
void	reverse_rotate_all(stack *stack_a, stack *stack_b)
{
	reverse_rotate_stack_a(stack_a);
	reverse_rotate_stack_b(stack_b);
	ft_printf("rrr\n");
}