#include "../includes/push_swap.h"

void	check(stack *stack);

int main(int ac, char *av[])
{
	int		i;
	stack	*stack_a;
	// stack	*stack_b;
	node	*new_node;
	
	if (ac < 2)
		quit();
	stack_a = (stack *)malloc(sizeof(stack));
	if (!stack_a)
		quit();
	stack_a->top = NULL;
	stack_a->size = 0;
	i = 1;
	while (i < ac)
	{
		if (is_num_str(av[i]) == FALSE)
			quit();
		new_node = create_new_node(ft_atoi(av[i]));
		if (!new_node)
			quit();
		add_to_bottom(stack_a, new_node);
		i++;
	}
	check(stack_a);
}


/*
*stack A and B each contains a linked list, aka the node struct
*maybe create a function to move things into both nodes
*/

/*
int main(void)
{
	// test;
}
*/

/*
int main(int ac, char *av[])
{
	if (ac < 2)
		quit();
	ft_printf("%i\nTrue: 1\nFalse: 0\n", is_num_str(av[1]));
}
*/

void	check(stack *stack)
{
	node *cur = stack->top;
	while (cur)
	{
		ft_printf("%i\n", cur->num);
		cur = cur->next;
	}
	reverse_rotate_stack_a(stack);
	cur = stack->top;
	while (cur)
	{
		ft_printf("%i\n", cur->num);
		cur = cur->next;
	}
}