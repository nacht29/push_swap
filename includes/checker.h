/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:19:25 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:19:25 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	checker(t_stack *og_stack_a, t_stack *ck_stack_b);
void	checking_process(char **operations, t_stack *og_stack_a, t_stack *ck_stack_b);
void	exec_oper(t_stack **og_stack_a, t_stack **ck_stack_b, char *oper);
int		is_oper(char **operations, char *s);

/*operations*/
void	ck_push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	ck_push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	ck_swap_a(t_stack **stack_a);
void	ck_swap_b(t_stack **stack_b);
void	ck_swap_all(t_stack **stack_a, t_stack **stack_b);
void	ck_rotate_a(t_stack **stack_a);
void	ck_rotate_b(t_stack **stack_b);
void	ck_rotate_all(t_stack **stack_a, t_stack **stack_b);
void	ck_reverse_rotate_a(t_stack **stack_a);
void	ck_reverse_rotate_b(t_stack **stack_b);
void	ck_reverse_rotate_all(t_stack **stack_a, t_stack **stack_b);
#endif