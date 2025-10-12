#include "push.h"

void ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
// t_list *makestack(int argc, char **argv)
// {
//     t_list *stack;
//     int value;
//     if (argc < 2)
//         ft_error();
//     else
//     {
//         int i;

//         i = 1;
//         stack = NULL;
//         while (argv[i])
//         {
//             value = ft_atoi(argv[i]);
//             ft_lstadd_back(&stack, ft_lstnew(value));
//             i++;
//         }
//     }
//     return (stack);
// }