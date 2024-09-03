#include "../includes/push_swap.h"

static int	get_max(stack *stack)
{
	int		max;
	node	*cur;

	cur = stack->top;
	max = cur->num;
	while (cur)
	{
		if (cur->num > max)
			max = cur->num;
		cur = cur->next;
	}
	return (max);
}

int	get_target_a(int target_a, stack *stack_b)
{
	node	*cur_b;
	int		target;
	int		closest_smaller;
	int		smaller_found;

	cur_b = stack_b->top;
	closest_smaller = INT_MIN;
	smaller_found = 0;
	while (cur_b)
	{
		if (cur_b->num < target_a && cur_b->num >= closest_smaller)
		{
			target = cur_b->num;
			closest_smaller = cur_b->num;
			smaller_found = 1;
		}
		cur_b = cur_b->next;
	}
	if (smaller_found == 0)
		target = get_max(stack_b);
	return (target);
}

