#ifndef CHEKCER_H
# define CHEKCER_H

# include "../libft/libft.h"
# include "../includes/push_swap.h"
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define A_TO_B 0
# define B_TO_A 1

/*=======*/
/*CHECKER*/
/*=======*/

/*checker*/
void	checker(stack *og_stack_a, stack *ck_stack_b);
void	checking_process(char **operations, stack *og_stack_a, stack *ck_stack_b);
void	exec_oper(stack **og_stack_a, stack **ck_stack_b, char *oper);
int		is_oper(char **operations, char *s);

/*operations*/
void	ck_push_a_to_b(stack **stack_a, stack **stack_b);
void	ck_push_b_to_a(stack **stack_a, stack **stack_b);
void	ck_swap_a(stack **stack_a);
void	ck_swap_b(stack **stack_b);
void	ck_swap_all(stack **stack_a, stack **stack_b);
void	ck_rotate_a(stack **stack_a);
void	ck_rotate_b(stack **stack_b);
void	ck_rotate_all(stack **stack_a, stack **stack_b);
void	ck_reverse_rotate_a(stack **stack_a);
void	ck_reverse_rotate_b(stack **stack_b);
void	ck_reverse_rotate_all(stack **stack_a, stack **stack_b);
#endif