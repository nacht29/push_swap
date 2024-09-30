/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:17 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:54:17 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
*pushes num on top of A -> B
*sets 2nd node of A as 1st node
*size A -1
*add_to_top: size B +1
*/
void	ck_push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*temp;

	if (!(*stack_a) || !((*stack_a)->top))
		return ;
	temp = (*stack_a)->top;
	(*stack_a)->top = (*stack_a)->top->next;
	(*stack_a)->size--;
	temp->next = NULL;
	add_to_top(*stack_b, temp);
	(*stack_b)->size++;
}

/*
*pushes num on top of B -> A
*sets 2nd node of B as 1st node
*size B -1
*add_to_top: size A +1
*/
void	ck_push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*temp;

	if (!(*stack_b) || !((*stack_b)->top))
		return ;
	temp = (*stack_b)->top;
	(*stack_b)->top = (*stack_b)->top->next;
	(*stack_b)->size--;
	temp->next = NULL;
	add_to_top((*stack_a), temp);
	(*stack_a)->size++;
}
