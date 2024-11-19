#include "push_swap.h"

void sa(t_node **stack_a)
{
    t_node *top;
    t_node *second;
    t_node *last;

    top = *stack_a;
    second = top->next;
    last = top->previous;
    if (second == top || !(*stack_a))
        return;
    else if (second->next == top)
    {
        *stack_a = second;
        write(1, "sa\n", 3);
        return;
    }
    else
    {
        top->next = last;
        top->previous = second;
        second->previous = last;
        second->next = top;
        last->previous = top;
        last->next = second;
    }
    *stack_a = second;
    write(1, "sa\n", 3);
}

void rra(t_node **stack_a)
{
    if (*stack_a == NULL)
        return;
    *stack_a = (*stack_a)->previous;
    write(1, "rra\n", 4);
}

void ra(t_node **stack_a)
{
    if (*stack_a == NULL)
        return;
    *stack_a = (*stack_a)->next;
    write(1, "ra\n", 3);
}


void pb(t_node **stack_a, t_node **stack_b)
{
    t_node *first_a;
    t_node *second_a;

    if (*stack_a == NULL)
        return;
    first_a = *stack_a;
    second_a = first_a->next;
    if (second_a == first_a)
        *stack_a = NULL;
    else
    {
        (*stack_a)->previous->next = second_a;
        second_a->previous = (*stack_a)->previous;
        *stack_a = second_a;
    }
    if (*stack_b == NULL)
    {
        *stack_b = first_a;
        first_a->next = first_a;
        first_a->previous = first_a;
    }
    else
        add_to_b(stack_b, first_a);
    write(1, "pb\n", 3);
}

void add_to_b(t_node **stack_b, t_node *first_a)
{
    first_a->next = *stack_b;
    first_a->previous = (*stack_b)->previous;
    (*stack_b)->previous->next = first_a;
    (*stack_b)->previous = first_a;
    *stack_b = first_a;
}
