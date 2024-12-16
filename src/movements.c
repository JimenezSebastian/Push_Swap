/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:19:58 by almejia-          #+#    #+#             */
/*   Updated: 2024/12/16 18:20:00 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	ra_rb(t_list **lst)
{
	t_list	*temp;
	t_list	*last;
	t_list	*temp2;

	temp = *lst;
	temp2 = temp->next;
	last = *lst;
	while (last->next)
		last = last->next;
	temp->next = NULL;
	last->next = temp;
	*lst = temp2;
}

void	rra_rrb(t_list **lst)
{
	t_list	*second_last;
	t_list	*last;

	second_last = *lst;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

/*
void rr(n_list **a, n_list **b)
{
	ra_rb(a);
	ra_rb(b);
}

void rrr(n_list **a, n_list **b)
{
	rra_rrb(a);
	rra_rrb(b);
}

void ss(n_list **a, n_list **b)
{	
	sa_sb(a);
	sa_sb(b);	
}
*/
