/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:43:49 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:43:49 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*boolean function
*returns TRUE is stack is sorted, else FALSE
*/
int	stack_is_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	while (cur->next)
	{
		if (cur->num > cur->next->num)
			return (FALSE);
		cur = cur->next;
	}
	return (TRUE);
}

/*
*finds the node containing the maximum value in a stack
*used when nodes in A cannot find target node in B
*/
t_node	*find_max(t_stack *stack)
{
	t_node	*cur;
	int		max;
	t_node	*max_node;

	cur = stack->top;
	max = INT_MIN;
	max_node = NULL;
	while (cur)
	{
		if (cur->num > max)
		{
			max = cur->num;
			max_node = cur;
		}
		cur = cur->next;
	}
	return (max_node);
}

/*
*finds the node containing the maximum value in a stack
*used when nodes in B cannot find target node in A
*/
t_node	*find_min(t_stack *stack)
{
	t_node	*cur;
	int		min;
	t_node	*min_node;

	cur = stack->top;
	min = INT_MAX;
	min_node = NULL;
	while (cur)
	{
		if (cur->num < min)
		{
			min = cur->num;
			min_node = cur;
		}
		cur = cur->next;
	}
	return (min_node);
}

/*
*locates and returns the cheapest node
*searches for node with [cheapest = TRUE]
*/
t_node	*get_cheapest(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->cheapest == TRUE)
			break ;
		cur = cur->next;
	}
	return (cur);
}
