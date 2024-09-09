#include "../includes/push_swap.h"

void	sort_two(stack **stack_a)
{
	node	*cur;

	cur = (*stack_a)->top;
	if (cur->num > cur->next->num)
		swap_a(stack_a);
}

void	sort_three(stack **stack_a)
{
	node	*cur;

	cur = (*stack_a)->top;
	if (cur->num > cur->next->num && cur->num > cur->next->next->num)
		rotate_a(stack_a);
	sort_two(stack_a);
}
