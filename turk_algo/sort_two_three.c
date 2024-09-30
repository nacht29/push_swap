/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:43:46 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:43:46 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack **stack_a)
{
	t_node	*cur;

	if ((*stack_a)->size != 2)
		return ;
	if (stack_is_sorted(*stack_a) == TRUE)
		return ;
	cur = (*stack_a)->top;
	if (cur->num > cur->next->num)
		swap_a(stack_a, TRUE);
}

void	sort_three(t_stack **stack_a)
{
	t_node	*biggest_node;

	if (stack_is_sorted(*stack_a) == TRUE)
		return ;
	biggest_node = find_max(*stack_a);
	if (biggest_node == (*stack_a)->top)
		rotate_a(stack_a, TRUE);
	if (biggest_node == (*stack_a)->top->next)
		reverse_rotate_a(stack_a, TRUE);
	if ((*stack_a)->top->num > (*stack_a)->top->next->num)
		swap_a(stack_a, TRUE);
}
