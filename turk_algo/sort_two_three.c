#include "../includes/push_swap.h"

void	sort_two(stack **stack_a)
{
	node	*cur;

	if ((*stack_a)->size != 2)
		return ;
	if (stack_is_sorted(*stack_a) == TRUE)
		return ;
	cur = (*stack_a)->top;
	if (cur->num > cur->next->num)
		swap_a(stack_a);
}

void	sort_three(stack **stack_a)
{
	node	*biggest_node;

	if (stack_is_sorted(*stack_a) == TRUE)
		return ;
	biggest_node = find_max(*stack_a);
	if (biggest_node == (*stack_a)->top)
		rotate_a(stack_a);
	if (biggest_node == (*stack_a)->top->next)
		reverse_rotate_a(stack_a);
	if ((*stack_a)->top->num > (*stack_a)->top->next->num)
		swap_a(stack_a);
}
