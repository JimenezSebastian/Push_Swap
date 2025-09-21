/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:03:05 by almejia-          #+#    #+#             */
/*   Updated: 2024/12/12 15:03:09 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	parse(int argc, char **argv, t_node **stack_a)
{
	int	*index;

	argv = cleaner_argv(argv, argc);
	argc = digits_checker(argv);
	index = make_index(argv, argc);
	stack_generator(stack_a, index, argc, argv);
	free_v2(NULL, index, argv);
	return (argc);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(1);
	argc = parse(argc, argv, &stack_a);
	if (argc <= 5 && verify(stack_a))
		sort_five_or_less(&stack_a, &stack_b, argc);
	algorithm(&stack_a, &stack_b);
	free_v2(&stack_a, NULL, NULL);
	return (0);
}
