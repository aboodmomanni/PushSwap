#include "push.h"

void ft_lstclear(t_list **lst)
{
    t_list *tmp;

    if (!lst || !*lst)
        return;
    while (*lst)
    {
        tmp = (*lst)->next;
        free(*lst);
        *lst = tmp;
    }
    *lst = NULL;
}
