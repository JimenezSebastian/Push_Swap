#include "push_swap.h"

int value_exists(n_list *stack_a, int p)
{
        n_list *temp;

        temp = stack_a;
        while (temp)
        {
                if ((int)temp->num == p)
                        return (1);
                temp = temp->next;
        }
        return (0);
}

void exit_error(void)
{
        ft_putstr_fd("Error", 1);
        exit(1);
}

n_list *lstnew(int content)
{
	n_list *newNode;

	newNode = malloc(sizeof(n_list));
	if (!newNode)
		return(NULL);
	newNode -> num = content;
	newNode -> next = NULL;
	return (newNode);
}

int lstadd_back(n_list **list, n_list *newNode)
{
	n_list *ptr;

	ptr = *list;
	if (!newNode)
		return(1);
	else if (!(*list))
	{
		*list = newNode;
		return(0);
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newNode;
	return (0);	
}

int lst_size(n_list *lst)
{
	int size;
	n_list *ptr;	
	
	ptr = lst;
	size = 0;
	while (ptr)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}

int get_max_bits(n_list *lst)
{
	int	max;
	n_list	*ptr;
	
	max = -2147483647;
	ptr = lst;
	while (ptr)
	{
		if (ptr->index > max)
			max = ptr->index;
		ptr = ptr->next;
	}

	return ((int)log2(max) + 1);
}
