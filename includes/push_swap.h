/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:19:47 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:59:50 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/*============*/
/*MAIN PROCESS*/
/*============*/

/*initialising and parsing stack A*/

void	init_stack_a(int ac, char **av, t_stack **stack_a);
void	parse_stack_a(int ac, char **av, t_stack **stack_a);

/*parse check*/

int		parse_check(char *num_str, t_stack *stack);
void	free_parse_data(t_stack **stack_a, char ***num_str_arr, char **num_str);
char	*combine_str(int ac, char **av);

/*utils*/

void	err_and_exit(void);
void	free_str_arr(char ***str_arr);

/*==========*/
/*OPERATIONS*/
/*==========*/

/*linked list manipulations*/

t_node	*append_node(int new_num);
void	add_to_top(t_stack *stack, t_node *new_node);
void	add_to_bottom(t_stack *stack, t_node *new_node);
void	free_whole_stack(t_stack **stack);

/*push*/

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);

/*swap*/

void	swap_a(t_stack **stack_a, int print);
void	swap_b(t_stack **stack_b, int print);
void	swap_all(t_stack **stack_a, t_stack **stack_b);

/*rotate*/

void	rotate_a(t_stack **stack_a, int print);
void	rotate_b(t_stack **stack_b, int print);
void	rotate_all(t_stack **stack_a, t_stack **stack_b);

/*reverse rotate*/

void	reverse_rotate_a(t_stack **stack_a, int print);
void	reverse_rotate_b(t_stack **stack_b, int print);
void	reverse_rotate_all(t_stack **stack_a, t_stack **stack_b);

/*reverse rotate*/

/*================*/
/*TURK'S ALGORITHM*/
/*================*/

/*sort 2 and sort 3*/

void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);

/*sort multiple*/
// main sorting process

void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	init_stack_b(t_stack **stack_b);
void	min_on_top(t_stack *stack_a);

/*initiate nodes and push*/
// push from a to b

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	set_target_a(t_stack *stack_a, t_stack *stack_b);;
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);

// push from b to a

void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	set_target_b(t_stack *stack_a, t_stack *stack_b);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);

/*init and move utils*/

void	index_median(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	cost_calc(t_stack *src_stack, t_stack *targ_stack);
void	bring_to_top(t_stack *stack, t_node *top_node, char stack_name);

/*sort utils*/

int		stack_is_sorted(t_stack *stack);
t_node	*find_max(t_stack *stack);
t_node	*find_min(t_stack *stack);
t_node	*get_cheapest(t_stack *stack);
#endif