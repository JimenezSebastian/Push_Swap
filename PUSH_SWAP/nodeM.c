#include "push_swap.h"

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

void sa(n_list **lst)
{
	n_list *first;
	n_list *second;

	first = *lst;
       	second = first->next;	
	first->next = second->next;
	second->next = first;
	first->next = second;
}

void sb(n_list **lst)
{
	n_list *first;
	n_list *second;

	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	first->next = second;
}

void ss(n_ls)
{
	
}
