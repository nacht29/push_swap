#include "../includes/push_swap.h"

/*
*pushes num on top of A -> B
*sets 2nd node of A as 1st node
*size A -1
*add_to_top: size B +1
*/
void	push_a_to_b(stack **stack_a, stack **stack_b)
{
	node	*temp;

	if (!(*stack_a) || !((*stack_a)->top))
		return;
	temp = (*stack_a)->top;
	(*stack_a)->top = (*stack_a)->top->next;
	(*stack_a)->size--;
	temp->next = NULL;
	add_to_top(*stack_b, temp);
	(*stack_b)->size++;
	ft_printf("pb\n");
	index_median(*stack_a);
	index_median(*stack_b);
}

/*
*pushes num on top of B -> A
*sets 2nd node of B as 1st node
*size B -1
*add_to_top: size A +1
*/
void	push_b_to_a(stack **stack_a, stack **stack_b)
{
	node	*temp;

	if (!(*stack_b) || !((*stack_b)->top))
		return;
	temp = (*stack_b)->top;
	(*stack_b)->top = (*stack_b)->top->next;
	(*stack_b)->size--;
	temp->next = NULL;
	add_to_top((*stack_a), temp);
	(*stack_a)->size++;
	ft_printf("pa\n");
	index_median(*stack_a);
	index_median(*stack_b);
}