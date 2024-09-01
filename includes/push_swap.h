#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	node;

typedef struct s_stack
{
	node	*top;
	int		size;
}	stack;

/*====*/
/*MAIN*/
/*====*/

void	init_stack(stack **stack_a, stack **stack_b);
void	parse_stack_a(int ac, char **av, stack **stack_a);

/*==========*/
/*OPERATIONS*/
/*==========*/

// push

void	push_a_to_b(stack *stack_a, stack *stack_b);
void	push_b_to_a(stack *stack_b, stack *stack_a);

// swap

void	swap_a(stack *stack_a);
void	swap_b(stack *stack_b);
void	swap_all(stack *stack_a, stack *stack_b);

// rotate

void	rotate_a(stack *stack_a);
void	rotate_b(stack *stack_b);
void	rotate_all(stack *stack_a, stack *stack_b);

// reverse rotate

void	reverse_rotate_a(stack *stack_a);
void	reverse_rotate_b(stack *stack_b);

/*======*/
/*UTILS*/
/*======*/

/*checks*/
// exit

void	quit(void);

// parsing

int	parse_check(char *num_str, stack *stack);

/*operations*/
// list-manipulation

node	*create_new_node(int new_num);
void	add_to_top(stack *stack, node *new_node);
void	add_to_bottom(stack *stack, node *new_node);
void	free_whole_stack(stack **stack);
// void	free_node_from_stack(stack **stack);
#endif