#include "../includes/push_swap.h"

/*
*swaps the top two numbers of a stack
*arguments: stack name
*/
static void	swap_nodes(stack *stack)
{
	node	*temp;

	temp = stack->top;
	stack->top = stack->top->next;
	stack->top->next = temp;
}

void	swap_a(stack *stack_a)
{

	if (!stack_a->top || !stack_a->top->next)
		return ;
	swap_nodes(stack_a);
	ft_printf("sa\n");
}

void	swap_b(stack *stack_b)
{
	if (!stack_b->top || !stack_b->top->next)
		return ;
	swap_nodes(stack_b);
	ft_printf("sb\n");
}

void	swap_all(stack *stack_a, stack *stack_b)
{
	if (!stack_a || !stack_b)
		return	;
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}