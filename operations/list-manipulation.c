/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list-manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:34:16 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:59:25 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*malloc and create a new node
*/
t_node	*append_node(int new_num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = new_num;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = FALSE;
	new_node->cheapest = FALSE;
	new_node->target_node = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*
*adds a new node to the start of a linked list
*/
void	add_to_top(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
}

/*
*adds a new node to the end of a linked list
*/
void	add_to_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (!stack || !new_node)
		return ;
	if (!stack->top)
	{
		stack->top = new_node;
		return ;
	}
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

/*
*frees the entire stack
*/
void	free_whole_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !(*stack))
		return ;
	current = (*stack)->top;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	(*stack)->top = NULL;
	(*stack)->size = 0;
}
