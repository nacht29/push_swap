#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define A_TO_B 0
# define B_TO_A 1

typedef struct s_node
{
	int				num;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_node	*next;
}	node;

typedef struct s_stack
{
	node	*top;
	int		size;
}	stack;

/*============*/
/*MAIN PROCESS*/
/*============*/

/*initialising and parsing stack A*/

void	init_stack_a(int ac, char **av, stack **stack_a);
void	parse_stack_a(int ac, char **av, stack **stack_a);

/*parsing check*/

int		parse_check(char *num_str, stack *stack);
void	free_parse_data(stack **stack_a, char ***num_str_arr, char **num_str);
char	*combine_str(int ac, char **av);

/*push_swap utils*/

void	err_and_exit(void);
int		stack_is_sorted(stack *stack);
void	show_content(stack *stack);

/*==========*/
/*OPERATIONS*/
/*==========*/

/*linked list manipulations*/

node	*append_node(int new_num);
void	add_to_top(stack *stack, node *new_node);
void	add_to_bottom(stack *stack, node *new_node);
void	free_whole_stack(stack **stack);

/*swap*/

void	swap_a(stack **stack_a);

/*================*/
/*TURK'S ALGORITHM*/
/*================*/

/*sort 2 and sort 3*/
void	sort_two(stack **stack_a);
void	sort_three(stack **stack_a);

/*sort multiple*/
void	sort_stacks(stack **stack_a, stack **stack_b);
#endif