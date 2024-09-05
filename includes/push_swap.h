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
	int				target;
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

/*STACK CHECK*/
void	check(stack *stack);

/*PARSING*/
// parsing process
void	init_stack(stack **stack_a, stack **stack_b);
void	parse_stack_a(int ac, char **av, stack **stack_a);
int		parse_check(char *num_str, stack *stack);

// error and exit
void	err_and_exit(void);
void	free_parse_data(stack **stack_a, char ***num_str_arr, char **num_str);

/*====*/
/*TURK*/
/*====*/

/*MAIN PROCESS*/

void	push_swap(stack *stack_a, stack *stack_b);
void	set_target_a(stack *stack_a, stack *stack_b);

/*UTILS*/
// target notes
int		get_target_a(int target_a, stack *stack_b);

// min/max num
int		get_max(stack *stack); // will be needed for sorting stack of 3 in a
int		get_min(stack *stack);

// check if stack si sorted
int		is_sorted(stack *stack);

/*==========*/
/*OPERATIONS*/
/*==========*/

/*PUSH*/

void	push_a_to_b(stack *stack_a, stack *stack_b);
void	push_b_to_a(stack *stack_b, stack *stack_a);

/*SWAP*/

void	swap_a(stack *stack_a);
void	swap_b(stack *stack_b);
void	swap_all(stack *stack_a, stack *stack_b);

/*ROTATE*/

void	rotate_a(stack *stack_a);
void	rotate_b(stack *stack_b);
void	rotate_all(stack *stack_a, stack *stack_b);

/*REVERSE ROTATE*/

void	reverse_rotate_a(stack *stack_a);
void	reverse_rotate_b(stack *stack_b);

/*======*/
/*UTILS*/
/*======*/

/*operations*/
// list-manipulation

node	*create_new_node(int new_num);
void	add_to_top(stack *stack, node *new_node);
void	add_to_bottom(stack *stack, node *new_node);
void	free_whole_stack(stack **stack);
// void	free_node_from_stack(stack **stack);
#endif