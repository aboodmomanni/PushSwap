#include "push.h"

void rra(t_list **a)
{
    t_list *prev = NULL;
    t_list *last = *a;

    if (!*a || !(*a)->next)
        return;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *a;
    *a = last;
    write(1, "rra\n", 4);
}

void rrb(t_list **b)
{
    t_list *prev = NULL;
    t_list *last = *b;

    if (!*b || !(*b)->next)
        return;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *b;
    *b = last;
    write(1, "rrb\n", 4);
}

void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}
