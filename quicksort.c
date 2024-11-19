#include "push_swap.h"

void    fill_indexes(t_node **stack_a, int count)
{
    int i;
    int array[count];
    t_node *current;

    i = 0;
    current = *stack_a;
    while (i < count)
    {
        array[i] = current->data;
        current = current->next;
        i++;
    }
    quicksort(array, 0, count-1);
    assign_indexes(stack_a, array, count);
}

void swap(int *array_1, int *array_2)
{
    int temp;

    temp = *array_1;
    *array_1 = *array_2;
    *array_2 = temp;
}

int partition(int *array, int start, int end)
{
    int pivot;
    int i;
    int j;

    pivot = array[end];
    i = start - 1;
    j = start;
    while(j < end)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
        j++;
    }
    swap(&array[++i], &array[j]);
    return (i);
}

void    quicksort(int *array, int start, int end)
{
    int pivot_index;

    if (start < end)
    {
        pivot_index = partition(array, start, end);
        quicksort(array, start, pivot_index - 1);
        quicksort(array, pivot_index + 1, end); 
    }
}

void    assign_indexes(t_node **stack_a, int *array, int count)
{
    t_node *current;
    int i;

    current = *stack_a;
    while (1)
    {
        i = 0;
        while (i < count)
        {
            if (current->data == array[i])
            {
                current->index = i;
                break;
            }
            i++;
        }
        current = current->next;
        if (current == *stack_a)
            break;
    }
}


