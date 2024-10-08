/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:43:39 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:43:39 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*sets the remaining values in each node in A
*sets:
-median
-target node
-push cost
*prepare to push to B
*/
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	index_median(stack_a);
	index_median(stack_b);
	set_target_a(stack_a, stack_b);
	cost_calc(stack_a, stack_b);
	set_cheapest(stack_a);
}

/*
*sets the target nodes for nodes in stack A
(the approx pos nodes A will be pushed to in B)
*it finds the node in B that's the closest and at the same time
smaller than node in A
*stack B is sorted in descending order
*/
void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	t_node	*targ;
	int		closest_smaller;

	cur_a = stack_a->top;
	while (cur_a)
	{
		cur_b = stack_b->top;
		closest_smaller = INT_MIN;
		while (cur_b)
		{
			if ((cur_b->num < cur_a->num) && (cur_b->num > closest_smaller))
			{
				closest_smaller = cur_b->num;
				targ = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (closest_smaller == INT_MIN)
			cur_a->target_node = find_max(stack_b);
		else
			cur_a->target_node = targ;
		cur_a = cur_a->next;
	}
}

/*
*simultaneously brings node in A and its target node above median
*does not perform rotations if the first node is alr in the 
correct pos
*accounts for when the cheapest node is on top
*then, work on individual stacks to bring the
push node and target node to the top of the stack
*/
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*cheapest;

	if (!stack_a || !(*stack_a) || !(*stack_a)->top)
		return ;
	cheapest = get_cheapest(*stack_a);
	if (!cheapest)
		return ;
	while ((*stack_a)->top != cheapest)
	{
		if (cheapest->above_median && cheapest->target_node->above_median)
			rotate_all(stack_a, stack_b);
		else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
			reverse_rotate_all(stack_a, stack_b);
		else
			break ;
	}
	bring_to_top(*stack_a, cheapest, 'a');
	bring_to_top(*stack_b, cheapest->target_node, 'b');
	push_a_to_b(stack_a, stack_b);
}
