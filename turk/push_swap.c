#include "../includes/push_swap.h"

void	push_swap(stack *stack_a, stack *stack_b)
{
	push_a_to_b(stack_a, stack_b);
	push_a_to_b(stack_a, stack_b);
	if (stack_a->size > 3)
		set_target_a(stack_a, stack_b);

	node	*cur = stack_a->top;
	while (cur)
	{
		ft_printf("num: %i target: %i\n", cur->num, cur->target);
		cur = cur->next;
	}
}

/*
*assign a value as target node 
*check if the target node is the first node
*/
void	set_target_a(stack *stack_a, stack *stack_b)
{
	node	*cur_a;
	
	cur_a = stack_a->top;
	while (cur_a)
	{
		cur_a->target = get_target_a(cur_a->num, stack_b);
		cur_a = cur_a->next;
	}
}
