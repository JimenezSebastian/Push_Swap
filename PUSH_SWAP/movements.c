void sa(n_list **lst)
{
	n_list *first;
	n_list *second;

	first = *lst;
       	second = first->next;	
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void sb(n_list **lst)
{
	n_list *first;
	n_list *second;

	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void ss(n_list stack_a, n_list stack_b)
{	
	sa(stack_a);
	sb(stack_b);	
}


