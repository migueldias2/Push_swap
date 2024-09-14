#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
    long data;
    int index;
    struct s_node *next;
    struct s_node *previous;
} t_node;

typedef struct s_info {
    int lb;
    int ub;
    int cs;
    int total;
    int p;
    int i;
} t_info;


int     validate_store_string(char *str, t_node **head);
int     validate_store_args(int argc, char **argv, t_node **head);
void    free_strings(char **strings);
void    free_linked_list(t_node **head);
int     isvalid_int(long num);
int     is_duplicated(long num, t_node **head);
int handle_error(char **strings, t_node **stack_a);
int     add_to_stack_a(long num, t_node **head);
long    ft_atol(char *str);
int     has_invalid_strings(char *str);
char    **ft_split(char *str);
int     count(char *str);
int     fill_list(char *str, char **list_strings, int i, int index);
void    fill_indexes(t_node **stack_a, int count);
void    swap(int *array_1, int *array_2);
int     partition(int *array, int start, int end);
void    quicksort(int *array, int start, int end);
void    assign_indexes(t_node **stack_a, int *array, int count);
void    sort(t_node **stack_a, int count);
int     is_sorted(t_node **stack_a);
void    sort_3(t_node **stack_a);
void sort_all(t_node **stack_a, t_node **stack_b, int count);
void sa(t_node **stack_a);
void rra(t_node **stack_a);
void ra(t_node **stack_a);
void pb(t_node **stack_a, t_node **stack_b);
void pa(t_node **stack_a, t_node **stack_b);
void rotate(int n, int count, t_node **stack_a);
void    sort_big(t_node **stack_a, t_node **stack_b, int count, int chunks);
void sort_all_2(t_node **stack_a, t_node **stack_b, int total_index);
void rb(t_node **stack_b);
void rrb(t_node **stack_b);
void print_stack(t_node **stack, const char *stack_name);
int find_bottom2(t_node **stack_b, int max_sorted_index);
int find_top2(t_node **stack_b, int max_sorted_index);
void push_back(int n, t_node **stack_a, t_node **stack_b);
void add_to_b(t_node **stack_b, t_node *first_a);
void push_to_a(t_node **stack_a, t_node *first_b);



#endif
