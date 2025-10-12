#include "push.h"

void ra(t_list **a)
{
    t_list *first;
    t_list *last;

    if (!*a || !(*a)->next)
        return;
    first = *a;
    *a = (*a)->next;
    first->next = NULL;
    last = *a;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1, "ra\n", 3);
}

void rb(t_list **b)
{
    t_list *first;
    t_list *last;

    if (!*b || !(*b)->next)
        return;
    first = *b;
    *b = (*b)->next;
    first->next = NULL;
    last = *b;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1, "rb\n", 3);
}

void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}
