#include "push_swap.h"

int validate_store_args(int argc,char **argv, t_node **head)
{
    int i;
    long num;

    i = 1;
    while(i < argc)
    {
        if (has_invalid_strings(argv[i]))
            return (0);
        else
        {
            num = ft_atol(argv[i]);
            if (!isvalid_int(num) || is_duplicated(num, head))
            {
                free_linked_list(head);
                return (0);
            }
            if (!add_to_stack_a(num, head))
            {
                free_linked_list(head);
                return (0);
            }
        }
        i++;
    }
    return (i-1);
}

int validate_store_string(char *str, t_node **head)
{
    char **strings;
    int i;
    long num;

    if (has_invalid_strings(str))
        return (0);
    strings = ft_split(str);
    if (!strings)
        return (0);
    i = 0;
    while (strings[i] != NULL)
    {
        num = ft_atol(strings[i]);
        if (!isvalid_int(num) || is_duplicated(num, head))
            return (handle_error(strings, head));
        if (!add_to_stack_a(num, head))
            return (handle_error(strings, head));
        i++;
    }
    free_strings(strings);
    return (i);
}

int main(int argc, char *argv[])
{
    t_node *stack_a;
    int count;
    
    count = 0;
    stack_a = NULL;
    if (argc == 1)
        return (0);
    if (argc == 2)
        count = validate_store_string(argv[1], &stack_a);
    else if (argc > 2)
        count = validate_store_args(argc, argv, &stack_a);
    if (count == 0)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if (is_sorted(&stack_a))
        return (0);
    fill_indexes(&stack_a, count);
    sort(&stack_a, count);
    free_linked_list(&stack_a);
    return (0);
}