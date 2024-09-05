#include "../includes/push_swap.h"

void	check(stack *stack)
{
	node *cur = stack->top;
	while (cur)
	{
		ft_printf("in stack: %i\n", cur->num);
		cur = cur->next;
	}
	reverse_rotate_a(stack);
	cur = stack->top;
	while (cur)
	{
		ft_printf("%i\n", cur->num);
		cur = cur->next;
	}
}