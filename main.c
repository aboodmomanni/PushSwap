#include "push.h"

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    int i;
    int value;

    if (argc < 2)
        ft_error();
    i = 1;
    a = NULL;
    b = NULL;
    while (argv[i])
    {
        value = ft_atoi(argv[i]);
        ft_lstadd_back(&a, ft_lstnew(value));
        i++;
    }
    if (!a)
        ft_error();
    if (checkDuplicates(a))
    {
        ft_lstclear(&a);
        ft_error();
    }
    if (checksorted(a))
    {
        ft_lstclear(&a);
        return (0);
    }
    getIndex(a);
    sortStack(&a, &b);
    ft_lstclear(&a);
    ft_lstclear(&b);
    return (0);
}
