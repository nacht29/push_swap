#include "../includes/push_swap.h"

void	reverse_rotate_stack(stack *stack)
{
	node	*first_node;
	node	*current;

	first_node = stack->top;
	stack->top = stack->top->next;
	current = stack->top;
	first_node->next = NULL;
	add_to_bottom(stack, first_node, 0);
}

// void	reverse_rotate_b(stack *stack_b)
// {
// 	node	*temp;

// 	temp = stack_b->top;
// 	free_node_from_stack(stack_b);
// 	add_to_bottom(stack_b, temp);
// 	ft_printf("rrb\n");
// }

// void	reverse_rotate_all(stack *stack_a, stack *stack_b)
// {
// 	void	reverse_rotate_a(stack *stack_a);
// 	void	reverse_rotate_a(stack *stack_b);
// 	ft_printf("rrr");
// }