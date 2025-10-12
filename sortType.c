#include "push.h"

void sortStack(t_list **a, t_list **b)
{
    int size = ft_lstsize(*a);

    if (size <= 1)
        return;
    else if (size == 2)
        sort_2(a);
    else if (size == 3)
        sort_3(a);
    else if (size <= 5)
        sort_4_5(a, b);
    else
        radix_sort(a, b);
}
