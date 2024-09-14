#include "push_swap.h"

void free_list(char **list_strings)
{
    int i;

    i = 0;
    if (!list_strings)
        return;
    while(list_strings[i] != NULL)
    {
        free(list_strings[i]);
        i++;
    }
    free(list_strings);
}

int fill_list(char *str, char **list_strings, int i, int index)
{
    int start;
    int j;

    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '\0')
            break;
        start = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
        list_strings[index] = malloc((i-start+1) * sizeof(char) + 1);
        if (!list_strings[index])
            return (0);
        j = 0;
        while(j < (i-start))
        {
            list_strings[index][j] = str[start + j];
            j++;
        }
        list_strings[index++][j] = '\0';
    }
    list_strings[index] = NULL;
    return (1);
}

int count(char *str)
{
    int i;
    int word_count;

    i = 0;
    word_count = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i])
            word_count++;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
    }
    return (word_count);
}

char** ft_split(char *str)
{
    int word_count;
    char **list_strings;

    word_count = count(str);
    if (word_count == 0)
        return (NULL);
    list_strings = malloc((word_count+1) * sizeof(char*));
    if (!list_strings)
        return (NULL);
    if (!fill_list(str, list_strings, 0, 0))
    {
        free_list(list_strings);
        return (NULL);
    }
    return (list_strings);
}
