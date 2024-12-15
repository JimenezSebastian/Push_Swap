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

#include "libft.h"

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stddef.h>

typedef struct n_list
{
        int num;
	int index;
        struct n_list *next;
}       n_list;

void tester_indx(int *index, int argc);
void test(n_list *stack_a);

// Parse
char **cleaner_argv(char **argv, int argc);
int digits_checker(char **argv);
int *make_index(char **argv, int argc);
void node_indexer_creator(n_list **stack_a, int *index, int argc);

// utils
int     find_min_index(n_list *stack);
int     value_exists(n_list *stack_a, int n);
void    exit_error(void);
n_list  *lstnew(int content);
int     lstadd_back(n_list **list, n_list *newNode);
int     lst_size(n_list *lst);
void    index_lst(n_list **stack_a, int *index);
void    overflow(char *str, int *index);
int     verify(n_list *stack_a);

// Movements
void	pb(n_list **a , n_list **b);
void	ra_rb(n_list **lst);
void	pa(n_list **a, n_list **b);
void    rra_rrb(n_list **lst);
void    sa_sb(n_list **lst);

// Algorithms   
void    algorithm(n_list **stack_a, n_list **stack_b);
void    array_sort(int *nums, int size_array);
void    sort_five_or_less(n_list **stack_a, n_list **stack_b, int argc);
void    sort_three(n_list **stack_a);

#endif
