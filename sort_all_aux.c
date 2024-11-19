#include "push_swap.h"

int find_top2(t_node **stack_b, int max_sorted_index)
{
    int n;
    t_node *current;

    n = 0;
    current = *stack_b;
    while(current->index != max_sorted_index)
    {
        current = current->next;
        n++;
    }
    return (n);
}

int find_bottom2(t_node **stack_b, int max_sorted_index)
{
    int j;
    t_node *current_2;

    j = 0;
    current_2 = (*stack_b)->previous;
    while (current_2->index != max_sorted_index)
    {
        current_2 = current_2->previous;
        j++;
    }
    return (j);
}

void sort_all_2(t_node **stack_a, t_node **stack_b, int biggest)
{
    int n;
    int j;

    while(biggest >= 0)
    {
        n = find_top2(stack_b, biggest);
        j = find_bottom2(stack_b, biggest);
        if (n <= j)
        {
            while(n > 0)
            {
                rb(stack_b);
                n--;
            }
        }
        else
        {
            while(j >= 0)
            {
                rrb(stack_b);
                j--;
            }
        }
        pa(stack_a, stack_b);
        biggest--;
    }
}

