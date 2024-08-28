#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stddef.h>

# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int					num;
	struct s_num_list	*next;
}	node;

typedef struct s_stack
{
	node	*top;
	int		size;
}	stack;


/*==========*/
/*OPERATIONS*/
/*==========*/

// push
void push_a_to_b(stack *stack_a, stack *stack_b);
void push_b_to_a(stack *stack_b, stack *stack_a);

// swap
void	swap_a(stack *stack_a);
void	swap_b(stack *stack_b);
void	swap_all(stack *stack_a, stack *stack_b);

// reverse rotate
void	reverse_rotate_stack_a(stack *stack_a);
void	reverse_rotate_stack_b(stack *stack_b);
void	reverse_rotate_all(stack *stack_a, stack *stack_b);

/*======*/
/*UTILS*/
/*======*/

// genereic
void	quit(const char *err_msg);

// str_check
int		is_num_str(char *s);
int		is_sign(char c);

// list-manipulation
node	*create_new_node(int new_num);
void	add_to_top(stack *stack, node *new_node, int size_flag);
void	add_to_bottom(stack *stack, node *new_node,  int size_flag);
void	free_node_from_stack(stack **stack);
#endif