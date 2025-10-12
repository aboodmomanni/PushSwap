#include "push.h"

static void initialization(t_list *stack)
{
    while (stack)
    {
        stack->i = -1;
        stack = stack->next;
    }
}

void getIndex(t_list *stack)
{
    t_list *tmp;
    int index = 0;
    int min_val;
    t_list *min_node;

    initialization(stack);
    while (1)
    {
        tmp = stack;
        min_val = INT_MAX;
        min_node = NULL;
        while (tmp)
        {
            if (tmp->i == -1 && tmp->val < min_val)
            {
                min_val = tmp->val;
                min_node = tmp;
            }
            tmp = tmp->next;
        }
        if (!min_node)
            break;
        min_node->i = index++;
    }
}

int checkDuplicates(t_list *stack)
{
    t_list *head;
    t_list *temp;

    head = stack;
    while (head)
    {
        temp = head->next;
        while (temp)
        {
            if (head->val == temp->val)
                return (1);
            temp = temp->next;
        }
        head = head->next;
    }
    return (0);
}

int checksorted(t_list *stack)
{
    while (stack && stack->next)
    {
        if (stack->val > stack->next->val)
            return 0;
        stack = stack->next;
    }
    return 1;
}