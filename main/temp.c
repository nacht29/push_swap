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

/*
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
*/


/*
*calculates size of linked list
*/
/*
int	get_size(stack *stack)
{
	int		size;
	node	*current;

	if (!stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
*/