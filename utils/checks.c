#include "../includes/push_swap.h"

void	quit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	is_num_str(char *s)
{
	if  (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s) == 1)
		s++;
	if (*s == '\0')
		return (TRUE);
	return (FALSE);
}

static int	is_duplicate(char *s, stack *stack)
{
	node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (ft_atoi(s) == cur->num)
			return (FALSE);
		cur = cur->next;
	}
	return (TRUE);
}

int	parse_check(char *num_str, stack *stack)
{
	if (is_num_str(num_str) == FALSE)
		return (FALSE);
	if (is_duplicate(num_str, stack) == FALSE)
		return (FALSE);
	if (ft_atol(num_str) > INT_MAX || ft_atol(num_str) < INT_MIN)
		return (FALSE);
	return (TRUE);
}