#include "push_swap.h"

void rrb(t_node **stack_b)
{
    t_node *last;

    last = (*stack_b)->previous;
    *stack_b = last;
    write(1, "rrb\n", 4);
}

void rb(t_node **stack_b)
{
    t_node *second;

    second = (*stack_b)->next;
    *stack_b = second;
    write(1, "rb\n", 3);
}

void print_stack(t_node **stack, const char *stack_name)
{
	(void)*stack_name;
    t_node *current = *stack;
    if (current == NULL)
    {
        return;
    }
    while (1)
    {
        current = current->next;
        if (current == *stack)
            break;
    }
}
