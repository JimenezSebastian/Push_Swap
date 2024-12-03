#include "push_swap.h"

void sa_sb(n_list **lst)
{
	n_list *first;
	n_list *second;

	first = *lst;
       	second = first->next;	
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void ss(n_list **a, n_list **b)
{	
	sa_sb(a);
	sa_sb(b);	
}

void pa(n_list **a, n_list **b)
{
	n_list  *temp;

	if (!(*b))
		return;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void pb(n_list **a , n_list **b)
{
	n_list *temp;

	if(!(*a))
		return;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void ra_rb(n_list **lst)
{
	n_list *temp;
	n_list *last;
	n_list *temp2;
	
	if (!lst)
		return;
	temp = *lst; // nodo 1
	temp2 = temp->next; // nodo 2
	last = *lst;
	while (last->next)
		last = last->next;
	temp->next = NULL; // nodo huerfanito - 
	last->next = temp; //penultimo nodo apuntando al huerfanito
	*lst = temp2; // nueva cabecera segundo nodo
}

void rr(n_list **a, n_list **b)
{
	ra_rb(a);
	ra_rb(b);
}

void rra_rrb(n_list **lst)
{
	n_list *second_last;
	n_list *last;

//	if (!lst || !lst->next)
//		return;
	second_last = *lst;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

void rrr(n_list **a, n_list **b)
{
	rra_rrb(a);
	rra_rrb(b);
}
