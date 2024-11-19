
#include "push_swap.h"


int has_invalid_strings(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' 
        || str[i] == '-' || str[i] == '\t' || str[i] == '+'))
        {
            return (1);
        }
        if (str[i] == '-' || str[i] == '+')
        {
            if ((i > 0) && !(str[i-1] == ' ' || str[i-1] == '\t'))
            {
                return (1);
            }
            if (str[i+1] == '\0' || !(str[i+1]>= '0' && str[i+1] <= '9'))
            {
                return (1);
            }
        }
        i++;
    }
    return (0);
}

void free_strings(char **strings)
{
    int i;

    i = 0;
    if (!strings)
        return ;
    while (strings[i] != NULL)
    {
        free(strings[i]);
        i++;
    }
    free(strings);
}

void free_linked_list(t_node **head)
{
    t_node *current;
    t_node *second;

    current = *head;
    second = current->next;
    if (!head || !*head)
        return ;
    while (1)
    {
        if (second == *head)
        {
            free(second);
            break;
        }
        free(second);
        second = second->next;
        
    }
    *head = NULL;
}

int handle_error(char **strings, t_node **stack_a)
{
    free_strings(strings);
    free_linked_list(stack_a);
    return (0);
}
