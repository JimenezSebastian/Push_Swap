/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:32:18 by almejia-          #+#    #+#             */
/*   Updated: 2024/11/16 13:54:34 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stddef.h>

typedef struct t_node
{
	int				num;
	int				index;
	struct t_node	*next;
}		t_node;

void	tester_indx(int *index, int argc);
void	test(t_node *stack_a);

char	**cleaner_argv(char **argv, int argc);
int		digits_checker(char **argv);
int		*make_index(char **argv, int argc);
void	stack_generator(t_node **stack_a, int *index, int argc, char **argv);

// Utils
int		find_min_index(t_node *stack);
int		value_exists(t_node *stack_a, int n);
int		lstadd_back(t_node **list, t_node *newNode);
int		lst_size(t_node *lst);
int		verify(t_node *stack_a);
void	index_lst(t_node **stack_a, int *index);
void	overflow(char *str, int *index, char **argv);
void	free_v2(t_node **stack, int *index, char **argv);
void	clean_exit(t_node **stack, int *index, char **argv);
t_node	*lstnew(int content);

// Movements
void	pb(t_node **a, t_node **b);
void	ra_rb(t_node **lst);
void	pa(t_node **a, t_node **b);
void	rra_rrb(t_node **lst);
void	sa_sb(t_node **lst);

// Algorithms   
void	algorithm(t_node **stack_a, t_node **stack_b);
void	array_sort(int *nums, int size_array);
void	sort_five_or_less(t_node **stack_a, t_node **stack_b, int argc);
void	sort_three(t_node **stack_a);

#endif