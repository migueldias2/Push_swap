#include "push_swap.h"

void rotate(int n, int count, t_node **stack_a)
{
    if (n > count/2)
    {
        while(count - n > 0)
        {
            rra(stack_a);
            n++;
        }
    }
    else
    {
        while(n > 0)
        {
            ra(stack_a);
            n--;
        }
    }
}

void sort_all(t_node **stack_a, t_node **stack_b, int count)
{
    t_node *current;
    int keep_count;
    int n;
    int min_sorted_index;

    min_sorted_index = 0;
    keep_count = count;
    while(count > 3)
    {
        n = 0;
        current = *stack_a;
        while(current->index != min_sorted_index)
        {
            current = current->next;
            n++;
        }
        min_sorted_index++;
        rotate(n, count, stack_a);
        pb(stack_a, stack_b);
        count--;
    }
    sort_3(stack_a);
    n = keep_count-3;
    push_back(n, stack_a, stack_b);
}

void push_back(int n, t_node **stack_a, t_node **stack_b)
{
    while (n > 0)
    {
        pa(stack_a, stack_b);
        n--;
    }
}
