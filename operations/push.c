#include "../includes/push_swap.h"

void push_a_to_b(stack *stack_a, stack *stack_b)
{
    node *temp;

    if (!stack_a || !stack_a->top)
        return;
    temp = stack_a->top;
    stack_a->top = stack_a->top->next;
    stack_a->size--;
    temp->next = NULL;
    add_to_top(stack_b, temp, 1);
    ft_printf("pb\n");
}

void push_b_to_a(stack *stack_b, stack *stack_a)
{
    node *temp;

    if (!stack_b || !stack_b->top)
        return;
    temp = stack_b->top;
    stack_b->top = stack_b->top->next;
    stack_b->size--;
    temp->next = NULL;
    add_to_top(stack_a, temp, 1);
    ft_printf("pa\n");
}