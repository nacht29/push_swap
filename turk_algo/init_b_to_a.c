/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:43:41 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:43:41 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	index_median(stack_a);
	index_median(stack_b);
	set_target_b(stack_a, stack_b);
}

/*
*sets the target nodes for nodes in stack B
(the approx pos nodes B will be pushed to in A)
*it finds the node in A that's the closest and at the same time
larger than node in B
*stack A is sorted in ascending order
*/
void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	t_node	*targ;
	int		closest_larger;

	cur_b = stack_b->top;
	while (cur_b)
	{
		cur_a = stack_a->top;
		closest_larger = INT_MAX;
		while (cur_a)
		{
			if (cur_a->num > cur_b->num && cur_a->num < closest_larger)
			{
				closest_larger = cur_a->num;
				targ = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (closest_larger == INT_MAX)
			cur_b->target_node = find_min(stack_a);
		else
			cur_b->target_node = targ;
		cur_b = cur_b->next;
	}
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	bring_to_top(*stack_a, (*stack_b)->top->target_node, 'a');
	push_b_to_a(stack_a, stack_b);
}
