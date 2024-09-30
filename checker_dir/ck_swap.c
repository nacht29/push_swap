/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:25 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:54:25 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
*swaps the top two numbers of a stack
*arguments: stack name
*/
static void	swap_nodes(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	first = (*stack)->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*stack)->top = second;
}

/*
*swaps the place of node 1 and node 2 in stack A
*n1: stack->top
*n2: stack->top->next
*temp = n1
*n1 = n2
*n2 = temp;
*/
void	ck_swap_a(t_stack **stack_a)
{
	if (!((*stack_a)->top) || !((*stack_a)->top->next))
		return ;
	swap_nodes(stack_a);
}

/*
*swaps the place of node 1 and node 2 in stack B
*n1: stack->top
*n2: stack->top->next
*temp = n1
*n1 = n2
*n2 = temp;
*/
void	ck_swap_b(t_stack **stack_b)
{
	if (!((*stack_b)->top) || !((*stack_b)->top->next))
		return ;
	swap_nodes(stack_b);
}

/*
*runs both swap_a() and swap_b()
*/
void	ck_swap_all(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return ;
	ck_swap_a(stack_a);
	ck_swap_b(stack_b);
}
