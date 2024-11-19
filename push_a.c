#include "push_swap.h"

void pa(t_node **stack_a, t_node **stack_b)
{
    t_node *first_b;
    t_node *second_b;

    if (*stack_b == NULL)
        return;
    first_b = *stack_b;
    second_b = first_b->next;
    if (second_b == first_b)
        *stack_b = NULL;
    else
    {
        (*stack_b)->previous->next = second_b;
        second_b->previous = (*stack_b)->previous;
        *stack_b = second_b;
    }
    if (*stack_a == NULL)
    {
        *stack_a = first_b;
        first_b->next = first_b;
        first_b->previous = first_b;
    }
    else
		push_to_a(stack_a, first_b);
    write(1, "pa\n", 3);
}

void push_to_a(t_node **stack_a, t_node *first_b)
{
    first_b->next = *stack_a;
    first_b->previous = (*stack_a)->previous;
    (*stack_a)->previous->next = first_b;
    (*stack_a)->previous = first_b;
    *stack_a = first_b;
}

