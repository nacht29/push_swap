#include "../includes/checker.h"

int main(int ac, char *av[])
{
	stack	*stack_a;
	stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		err_and_exit();
	else
		init_stack_a(ac, av, &stack_a);
	checker(stack_a, stack_b);
}

void	checker(stack *stack_a, stack *stack_b)
{
	char	*all_ops;
	char	**operations;

	init_stack_b(&stack_b);
	all_ops = "pa pb sa sb ss ra rb rr rra rrb rrr";
	operations = ft_split(all_ops, ' ');
	checking_process(operations, stack_a, stack_b);
}

void	checking_process(char **operations, stack *stack_a, stack *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);

		if (line == NULL)
		{
			free(line);
			break ;
		}
		if (is_oper(operations, line) == TRUE)
			exec_oper(&stack_a, &stack_b, line);
		free(line);
	}
	if (stack_is_sorted(stack_a) == TRUE)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	exec_oper(stack **stack_a, stack **stack_b, char *oper)
{
	oper = ft_strtrim(oper, "\n");
	if (ft_strncmp(oper, "pb", ft_strlen(oper)) == 0)
		ck_push_a_to_b(stack_a, stack_b);
	else if (ft_strncmp(oper, "pa", ft_strlen(oper)) == 0)
		ck_push_b_to_a(stack_a, stack_b);
	else if (ft_strncmp(oper, "sa", ft_strlen(oper)) ==  0)
		ck_swap_a(stack_a);
	else if (ft_strncmp(oper, "sb", ft_strlen(oper)) ==  0)
		ck_swap_b(stack_b);
	else if (ft_strncmp(oper, "ss", ft_strlen(oper)) ==  0)
		ck_swap_all(stack_a, stack_b);
	else if (ft_strncmp(oper, "ra", ft_strlen(oper)) ==  0)
		ck_rotate_a(stack_a);
	else if (ft_strncmp(oper, "rb", ft_strlen(oper)) ==  0)
		ck_rotate_b(stack_b);
	else if (ft_strncmp(oper, "rr", ft_strlen(oper)) ==  0)
		ck_rotate_all(stack_a, stack_b);
	else if (ft_strncmp(oper, "rra", ft_strlen(oper)) ==  0)
		ck_reverse_rotate_a(stack_a);
	else if (ft_strncmp(oper, "rrb", ft_strlen(oper)) ==  0)
		ck_reverse_rotate_b(stack_b);
	else if (ft_strncmp(oper, "rrr", ft_strlen(oper)) ==  0)
		ck_reverse_rotate_all(stack_a, stack_b);
}

int	is_oper(char **operations, char *s)
{
	size_t	len;
	char	**op_ptr = operations;

	while (*op_ptr)
	{
		len = ft_strlen(*op_ptr);
		if (ft_strncmp(*op_ptr, s, len) == 0)
			return (TRUE);
		op_ptr++;
	}
	return (FALSE);
}
