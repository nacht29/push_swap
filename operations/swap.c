#include "../includes/push_swap.h"

/*
*swaps the top two numbers of a stack
*arguments: stack name
*/
static void	swap_nodes(stack **stack)
{
	node	*first;
	node	*second;

	first = (*stack)->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*stack)->top = second;
	index_median(*stack);
}

/*
*swaps the place of node 1 and node 2 in stack A
*n1: stack->top
*n2: stack->top->next
*temp = n1
*n1 = n2
*n2 = temp;
*/
void	swap_a(stack **stack_a, int print)
{

	if (!((*stack_a)->top) || !((*stack_a)->top->next))
		return ;
	swap_nodes(stack_a);
	if (print == TRUE)
		ft_printf("sa\n");
}

/*
*swaps the place of node 1 and node 2 in stack B
*n1: stack->top
*n2: stack->top->next
*temp = n1
*n1 = n2
*n2 = temp;
*/
void	swap_b(stack **stack_b, int print)
{

	if (!((*stack_b)->top) || !((*stack_b)->top->next))
		return ;
	swap_nodes(stack_b);
	ft_printf("sb\n");
}

/*
*runs both swap_a() and swap_b()
*/
void	swap_all(stack **stack_a, stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return	;
	swap_a(stack_a, FALSE);
	swap_b(stack_b, FALSE);
	ft_printf("ss\n");
}
