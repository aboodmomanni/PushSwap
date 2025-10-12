#include "push.h"

void sort_2(t_list **a)
{
    if ((*a)->val > (*a)->next->val)
        sa(a);
}

void sort_3(t_list **stack)
{
    while (!checksorted(*stack))
    {
        if ((*stack)->val > (*stack)->next->val)
            sa(stack);
        else if ((*stack)->next->val > (*stack)->next->next->val)
            rra(stack);
        else
            ra(stack);
    }
}

static int position(t_list *stack, int index)
{
    int pos = 0;

    while (stack)
    {
        if (stack->i == index)
            return pos;
        stack = stack->next;
        pos++;
    }
    return -1;
}

static void pushTob(t_list **a, t_list **b, int min_index)
{
    int pos;
    int size;

    size = ft_lstsize(*a);
    pos = position(*a, min_index);

    if (pos == -1)
        return;

    if (pos <= size / 2)
        while (pos-- > 0)
            ra(a);
    else
        while (pos++ < size)
            rra(a);

    pb(a, b);
}

void sort_4_5(t_list **a, t_list **b)
{
    int size;
    int min_index;

    size = ft_lstsize(*a);
    min_index = 0;
    while (size > 3)
    {
        pushTob(a, b, min_index++);
        size--;
    }
    sort_3(a);
    while (*b)
        pa(a, b);
}
