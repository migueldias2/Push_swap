/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:19:57 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/09/14 17:38:22 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_top(t_node **stack, t_info *info)
{
    t_node *curr = *stack;
    int dist = 0;

    while (!(curr->index >= info->lb && curr->index < info->ub))
    {
        curr = curr->next;
        dist++;
    }
    return dist;
}

int find_bottom(t_node **stack, t_info *info)
{
    t_node *curr = (*stack)->previous;
    int dist = 0;

    while (!(curr->index >= info->lb && curr->index < info->ub))
    {
        curr = curr->previous;
        dist++;
    }
    return dist;
}

void move_to_top(t_node **stack, int top_dist, int bottom_dist)
{
    if (top_dist < bottom_dist)
    {
        while (top_dist-- > 0)
            ra(stack);
    }
    else
    {
        while (bottom_dist-- >= 0)
            rra(stack);
    }
}

void adjust_bounds(t_info *info, int ch)
{
    if (info->i == ch)
        info->ub = info->total;
    else
        info->ub = info->lb + info->cs;
}

void sort_big(t_node **stack_a, t_node **stack_b, int cnt, int ch)
{
    t_info info;
    info.cs = cnt / ch;
    info.lb = 0;
    info.i = 1;
    info.p = 0;
    info.total = cnt;

    adjust_bounds(&info, ch);
    while (info.i <= ch)
    {
        int top_dist = find_top(stack_a, &info);
        int bottom_dist = find_bottom(stack_a, &info);
        move_to_top(stack_a, top_dist, bottom_dist);
        pb(stack_a, stack_b);
        info.p++;
        if (info.p == info.ub)
        {
            info.lb += info.cs;
            info.i++;
            adjust_bounds(&info, ch);
        }
    }
    sort_all_2(stack_a, stack_b, info.total - 1);
}
