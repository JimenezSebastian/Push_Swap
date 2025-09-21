/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:48:41 by almejia-          #+#    #+#             */
/*   Updated: 2024/12/12 17:48:44 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algorithm(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	size = lst_size(*stack_a);
	while (verify(*stack_a))
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				(pb(stack_a, stack_b), write(1, "pb\n", 3));
			else
				(ra_rb(stack_a), write(1, "ra\n", 3));
			j++;
		}
		while (*stack_b)
			(pa(stack_a, stack_b), write(1, "pa\n", 3));
		i++;
	}
}

void	array_sort(int *nums, int size_array)
{
	int	i;
	int	flag;
	int	temp;

	while (1)
	{
		i = 0;
		flag = 0;
		while (i < (size_array - 1))
		{
			if (nums[i] > nums[i + 1])
			{
				temp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
				flag = 1;
			}
			++i;
		}
		if (flag == 0)
			break ;
	}
}

void	sort_five_or_less(t_node **stack_a, t_node **stack_b, int argc)
{
	int	min_index;
	int	stack_size;

	while (argc > 3)
	{
		min_index = find_min_index(*stack_a);
		stack_size = lst_size(*stack_a);
		if (min_index <= stack_size / 2)
			while (min_index-- > 0)
				(ra_rb(stack_a), write(1, "ra\n", 3));
		else
			while (stack_size - min_index++ > 0)
				(rra_rrb(stack_a), write(1, "rra\n", 4));
		(pb(stack_a, stack_b), write(1, "pb\n", 3));
		argc--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
		if ((*stack_a)->index > (*stack_a)->next->index)
			(ra_rb(stack_a), write(1, "ra\n", 3));
	}
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		(sa_sb(stack_a), write(1, "sa\n", 3));
	else if (first > second && second > third)
	{
		(sa_sb(stack_a), write(1, "sa\n", 3));
		(rra_rrb(stack_a), write(1, "rra\n", 4));
	}
	else if (first > second && second < third && first > third)
		(ra_rb(stack_a), write(1, "ra\n", 3));
	else if (first < second && second > third && first < third)
	{
		(sa_sb(stack_a), write(1, "sa\n", 3));
		(ra_rb(stack_a), write(1, "ra\n", 3));
	}
	else if (first < second && second > third && first > third)
		(rra_rrb(stack_a), write(1, "rra\n", 4));
}
