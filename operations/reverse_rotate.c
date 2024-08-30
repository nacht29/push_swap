#include "../includes/push_swap.h"

static void	*get_last_node(stack *stack)
{
	node	*last_node;
	
	if (!stack->top)
		return (NULL);
	last_node = stack->top;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

static void	*get_sec_last_node(stack *stack)
{
	node	*sec_last_node;
	node	*temp;
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

void	reverse_rotate_stack_a(stack *stack_a)
{
	node	*last_node;
	node	*sec_last_node;

	if (stack_a->size <= 1)
		return ;
	last_node = get_last_node(stack_a);
	sec_last_node = get_sec_last_node(stack_a);
	add_to_top(stack_a, last_node);
	sec_last_node->next = NULL;
	free(last_node);
}

void	reverse_rotate_stack_b(stack *stack_b)
{
	node	*last_node;
	node	*sec_last_node;

	if (stack_b->size <= 1)
		return ;
	last_node = get_last_node(stack_b);
	sec_last_node = get_sec_last_node(stack_b);
	add_to_top(stack_b, last_node );
	sec_last_node->next = NULL;
	free(last_node);
}

/*
static void	*get_sec_last_node(stack *stack)
{
	node	*sec_last_node;
	node	*temp;
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
*/