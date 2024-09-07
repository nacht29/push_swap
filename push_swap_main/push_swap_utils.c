#include "../includes/push_swap.h"

void	err_and_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	stack_is_sorted(stack *stack)
{
	node	*cur;
	cur = stack->top;

	while (cur->next)
	{
		if (cur->num > cur->next->num)
			return (FALSE);
		cur = cur->next;
	}
	return (TRUE);
}

void	show_content(stack *stack)
{
	node	*cur;

	cur = stack->top;
	while (cur)
	{
		ft_printf("%i\n", cur->num);
		cur = cur->next;
	}
}