/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:19:38 by almejia-          #+#    #+#             */
/*   Updated: 2024/12/16 18:19:40 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	value_exists(t_node *stack_a, int n)
{
	t_node	*temp;

	temp = stack_a;
	while (temp)
	{
		if ((int)temp->num == n)
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_node	*lstnew(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node -> num = content;
	new_node -> next = NULL;
	return (new_node);
}

int	lstadd_back(t_node **list, t_node *newNode)
{
	t_node	*ptr;

	ptr = *list;
	if (!newNode)
		return (1);
	else if (!(*list))
	{
		*list = newNode;
		return (0);
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newNode;
	return (0);
}

int	lst_size(t_node *lst)
{
	int		size;
	t_node	*ptr;	

	ptr = lst;
	size = 0;
	while (ptr)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}

void	index_lst(t_node **stack_a, int *index)
{
	int		i;
	t_node	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		i = 0;
		while (ptr->num != index[i])
			i++;
		ptr->index = i;
		ptr = ptr->next;
	}
}
