
#include "push.h"

t_list *ft_lstnew(int content)
{
	t_list *t;

	t = malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->val = content;
	t->i=-1;
	t->next = NULL;
	return (t);
}
