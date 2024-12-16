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

# include "libft.h"

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stddef.h>

typedef struct t_list
{
	int				num;
	int				index;
	struct t_list	*next;
}		t_list;

void	tester_indx(int *index, int argc);
void	test(t_list *stack_a);

char	**cleaner_argv(char **argv, int argc);
int		digits_checker(char **argv);
int		*make_index(char **argv, int argc);
void	stack_generator(t_list **stack_a, int *index, int argc, char **argv);

// Utils
int		find_min_index(t_list *stack);
int		value_exists(t_list *stack_a, int n);
int		lstadd_back(t_list **list, t_list *newNode);
int		lst_size(t_list *lst);
int		verify(t_list *stack_a);
void	index_lst(t_list **stack_a, int *index);
void	overflow(char *str, int *index, char **argv);
void	free_v2(t_list **stack, int *index, char **argv);
void	clean_exit(t_list **stack, int *index, char **argv);
t_list	*lstnew(int content);

// Movements
void	pb(t_list **a, t_list **b);
void	ra_rb(t_list **lst);
void	pa(t_list **a, t_list **b);
void	rra_rrb(t_list **lst);
void	sa_sb(t_list **lst);

// Algorithms   
void	algorithm(t_list **stack_a, t_list **stack_b);
void	array_sort(int *nums, int size_array);
void	sort_five_or_less(t_list **stack_a, t_list **stack_b, int argc);
void	sort_three(t_list **stack_a);

#endif