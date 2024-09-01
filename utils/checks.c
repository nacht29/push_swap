#include "../includes/push_swap.h"

void	quit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

int	is_num_str(char *s)
{
	if  (is_sign(*s) == TRUE)
		s++;
	while (ft_isdigit(*s) == 1)
		s++;
	if (*s == '\0')
		return (TRUE);
	return (FALSE);
}
