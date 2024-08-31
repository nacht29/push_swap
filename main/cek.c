#include "../includes/push_swap.h"

void	check_push(stack *stack_a, stack *stack_b)
{
	node *cur;
	
	push_a_to_b(stack_a, stack_b);
	push_a_to_b(stack_a, stack_b);
	cur = stack_b->top;
	while (cur)
	{
		ft_printf("%i\n", cur->num);
		cur = cur->next;
	}
}

void	check(stack *stack)
{
	node *cur = stack->top;
	while (cur)
	{
		ft_printf("%i\n", cur->num);
		cur = cur->next;
	}
	reverse_rotate_stack_a(stack);
	cur = stack->top;
	while (cur)
	{
		ft_printf("%i\n", cur->num);
		cur = cur->next;
	}
}