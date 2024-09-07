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
	return ;
}
