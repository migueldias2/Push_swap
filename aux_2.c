#include "push_swap.h"

long ft_atol(char *str)
{
    long result;
    int sinal;
    int i;

    i = 0;
    result = 0;
    sinal = 1;
    if (str[i] == '-')
    {
        sinal = -sinal;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sinal);
}

int isvalid_int(long num)
{
    return (num <= 2147483647 && num >= -2147483648);
}

int is_duplicated(long num, t_node **head)
{
    t_node *current;
 
    current = *head;
    if (!current)
        return (0);
    while (1)
    {
        if (current->data == num)
            return (1);
        current = current->next;
        if (current == *head)
            break;
    }
    return (0);
}

int add_to_stack_a(long num, t_node **head)
{
    t_node *new_node;
    t_node *current;

    new_node = (t_node*)malloc(sizeof(t_node));
    if (!new_node)
        return (0);
    new_node->data = num;
    if (*head == NULL)
    {
        *head = new_node;
        new_node->next = new_node;
        new_node->previous = new_node;
        return (1);
    }
    current = *head;
    while (current->next != *head)
        current = current->next;
    new_node->previous = current;
    new_node->next = *head;
    current->next = new_node;
    (*head)->previous = new_node;
    return (1);
}

int is_sorted(t_node **stack_a)
{
    t_node *current;

    current = *stack_a;
    while (current->next != *stack_a)
    {
        if (current->data > current->next->data)
            return (0);
        current = current->next;
    }
    free_linked_list(stack_a);
    return (1);
}
