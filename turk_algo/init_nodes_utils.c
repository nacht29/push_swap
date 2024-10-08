/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:43:43 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:43:43 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*determine if the current node is above or below median line
*used to determine the least costly operation to perform
to bring the node to the correct pos
*/
void	index_median(t_stack *stack)
{
	t_node	*cur;
	int		median;
	int		i;

	if (!stack || !(stack->top))
		return ;
	cur = stack->top;
	median = stack->size / 2;
	i = 0;
	while (cur)
	{
		cur->index = i;
		if (i < median)
			cur->above_median = TRUE;
		else
			cur->above_median = FALSE;
		cur = cur->next;
		i++;
	}
}

/*
*search for the cheapest node to push
*the default cheapest push cost is INT_MAX
*function iterates through the stack
*the node with the lower push cost than the previous lowest
will temporarily be recorded as cheapest
*finally, the final, cheapest node will have its [cheapest] flag
set to TRUE
*hence, if no node is cheaper than the first, the first node is the
cheapest
*/
void	set_cheapest(t_stack *stack)
{
	t_node	*cur;
	t_node	*cur_cheapest;
	int		cheapest_cost;

	if (!stack)
		return ;
	cur = stack->top;
	cheapest_cost = INT_MAX;
	while (cur)
	{
		if (cur->push_cost < cheapest_cost)
		{
			cheapest_cost = cur->push_cost;
			cur_cheapest = cur;
		}
		cur = cur->next;
	}
	cur_cheapest->cheapest = TRUE;
}

/*
*calculate the cost of pushing a node from one stack
to the other
*push cost is calculated by the number of steps needed to bring
the push node and its target node to the correct pos
(most likely on top of the stack)
*/

void	cost_calc(t_stack *stack_a, t_stack *stack_b)
{
	int		size_a;
	int		size_b;
	t_node	*cur;

	size_a = stack_a->size;
	size_b = stack_b->size;
	cur = stack_a->top;
	while (cur)
	{
		cur->push_cost = cur->index;
		if (cur->above_median == FALSE)
			cur->push_cost = size_a - (cur->index);
		if (cur->target_node->above_median == TRUE)
			cur->push_cost += cur->target_node->index;
		else
			cur->push_cost += size_b - (cur->target_node->index);
		cur = cur->next;
	}
}

/*
*used in conjunction with move_*to_* functions
*individually works on stacks A and B to 
bring a node to the top of the stack
*/

void	bring_to_top(t_stack *stack, t_node *top_node, char stack_name)
{
	while (stack->top != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median == TRUE)
				rotate_a(&stack, TRUE);
			else
				reverse_rotate_a(&stack, TRUE);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median == TRUE)
				rotate_b(&stack, TRUE);
			else
				reverse_rotate_b(&stack, TRUE);
		}
	}
}
