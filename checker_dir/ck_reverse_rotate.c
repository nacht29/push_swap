/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:20 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:54:20 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	*get_last_node(t_stack *stack)
{
	t_node	*last_node;

	if (!(stack->top))
		return (NULL);
	last_node = stack->top;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

static void	*get_sec_last_node(t_stack *stack)
{
	t_node	*sec_last_node;
	t_node	*temp;
	int		i;

	if (!stack->top)
		return (NULL);
	i = 0;
	temp = stack->top;
	sec_last_node = stack->top;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	while ((i - 1) > 0)
	{
		sec_last_node = sec_last_node->next;
		i--;
	}
	return (sec_last_node);
}

void	ck_reverse_rotate_a(t_stack **stack_a)
{
	t_node	*last_node;
	t_node	*sec_last_node;

	if ((*stack_a)->size <= 1)
		return ;
	last_node = get_last_node(*stack_a);
	sec_last_node = get_sec_last_node(*stack_a);
	add_to_top(*stack_a, last_node);
	sec_last_node->next = NULL;
}

void	ck_reverse_rotate_b(t_stack **stack_b)
{
	t_node	*last_node;
	t_node	*sec_last_node;

	if ((*stack_b)->size <= 1)
		return ;
	last_node = get_last_node(*stack_b);
	sec_last_node = get_sec_last_node(*stack_b);
	add_to_top(*stack_b, last_node);
	sec_last_node->next = NULL;
}

void	ck_reverse_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	ck_reverse_rotate_a(stack_a);
	ck_reverse_rotate_b(stack_b);
}
