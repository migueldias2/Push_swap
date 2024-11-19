#include "push_swap.h"


void handle_first_cases(t_node **stack_a, t_node *current, int second, int third)
{
    if (current->data > second && current->data < third)
        sa(stack_a);
    else if (current->data < second && current->data > third)
        rra(stack_a);
    else if (current->data > second && current->data > third && second < third)
    {
        sa(stack_a);
        rra(stack_a);
        sa(stack_a);
    }
}
void handle_second_cases(t_node **stack_a, t_node *current, int second, int third)
{
    if (current->data < second && current->data < third && second > third)
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (current->data > second && current->data > third && second > third)
    {
        ra(stack_a);
        sa(stack_a);
    }
}
void sort_3(t_node **stack_a)
{
    t_node *current;
    int second;
    int third;

    current = *stack_a;
    second = current->next->data;
    third = current->previous->data;
    handle_first_cases(stack_a, current, second, third);
    handle_second_cases(stack_a, current, second, third);
}


void    sort(t_node **stack_a, int count)
{
    t_node *current;
    t_node *stack_b;

    stack_b = NULL;
    current = *stack_a;
    if (count == 2)
    {
        if (current->data > current->next->data)
            sa(stack_a);
    }
    else if (count == 3)
        sort_3(stack_a);
    else if (count > 3 && count < 10)
        sort_all(stack_a, &stack_b, count);
    else if (count >= 10 && count < 500)
        sort_big(stack_a, &stack_b, count, 5);
    else if (count >= 500)
        sort_big(stack_a, &stack_b, count, 11);
}


