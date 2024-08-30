#include "../includes/push_swap.h"

void	quit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

int	is_num_str(char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s) == 0)
			return (FALSE);
		s++;
	}
	return (TRUE);
}

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