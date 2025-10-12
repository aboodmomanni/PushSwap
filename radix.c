#include "push.h"

static int get_max_bits(t_list *stack)
{
    int max;
    int bits;

    if (!stack)
        return (0);
    max = stack->i;
    while (stack)
    {
        if (stack->i > max)
            max = stack->i;
        stack = stack->next;
    }
    bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

void radix_sort(t_list **a, t_list **b)
{
    int i;
    int j;
    int size;
    int max_bits;

    size = ft_lstsize(*a);
    max_bits = get_max_bits(*a);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*a)->i >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}
