#include "../includes/push_swap.h"

void	err_and_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	*combine_str(int ac, char **av)
{
	int		i;
	char	*line;
	char	*temp;
	char	*with_spc;

	i = 1;
	line = ft_strdup("");
	while (i < ac)
	{
		with_spc = ft_strjoin(" ", av[i]);
		temp = ft_strjoin(line, with_spc);
		free(line);
		free(with_spc);
		line = temp;
		i++;
	}
	return (line);
}