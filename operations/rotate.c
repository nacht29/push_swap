/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:34:23 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:34:23 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*Shift up all elements of stack A by 1.
The first element becomes the last one.
*
*As seem, stack->top is replaced by stack->top-next
1st node is replaced by 2nd node
nodes are shifted up
*
*Steps:
*1.Remove the first node: Detach the first node from the list.
*2.Traverse to the last node: Find the last node in the list.
*3.Attach the first node after the last node: 
Make the previously first node the new last node.
*4.Update the head of the list: Set the second node as the new 
head of the list.
*/
void	rotate_a(t_stack **stack_a, int print)
{
	t_node	*first_node;

	if ((*stack_a)->size <= 1)
		return ;
	first_node = (*stack_a)->top;
	(*stack_a)->top = (*stack_a)->top->next;
	first_node->next = NULL;
	add_to_bottom(*stack_a, first_node);
	index_median(*stack_a);
	if (print == TRUE)
		ft_printf("ra\n");
}

/*
*Shift up all elements of stack B by 1.
The first element becomes the last one.
*
*As seem, stack->top is replaced by stack->top-next
1st node is replaced by 2nd node
nodes are shifted up
*
*Steps:
*1.Remove the first node: Detach the first node from the list.
*2.Traverse to the last node: Find the last node in the list.
*3.Attach the first node after the last node: 
Make the previously first node the new last node.
*4.Update the head of the list: Set the second node as the new 
head of the list.
*/
void	rotate_b(t_stack **stack_b, int print)
{
	t_node	*first_node;

	if ((*stack_b)->size <= 1)
		return ;
	first_node = (*stack_b)->top;
	(*stack_b)->top = (*stack_b)->top->next;
	first_node->next = NULL;
	add_to_bottom(*stack_b, first_node);
	index_median(*stack_b);
	if (print == TRUE)
		ft_printf("rb\n");
}

/*
*reverse rotates stacks A and B
*/
void	rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a, FALSE);
	rotate_b(stack_b, FALSE);
	ft_printf("rr\n");
}
