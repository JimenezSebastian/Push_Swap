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
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <math.h>

typedef struct n_list
{
        int num;
	int index;
        struct n_list *next;
}       n_list;

void	index_lst(n_list **stack_a, int *nums);
void    exit_error(void);
void 	array_sort(int *nums, int size);
void	parse(int argc, char **argv, n_list **stack);
void    create_nodes(char **r, n_list **stack_a);

char	**clean_argv(char **argv, int argc);

int     lstadd_back(n_list **list, n_list *new_node);
int	value_exists(n_list *stack_a, int p);
int	*make_index(char **newArgv, int size_array);
int	no_int(char **newArgv);
int	get_max_bits(n_list *lst);
int	lst_size(n_list *lst);

n_list	*lstnew(int content);

void	pb(n_list **a , n_list **b);
void	ra_rb(n_list **lst);
void	pa(n_list **a, n_list **b);

#endif
