/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:32:18 by almejia-          #+#    #+#             */
/*   Updated: 2024/11/01 17:36:22 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"

typedef struct n_list
{
        int num;
	int index;
        struct n_list *next;
}       n_list;

void    exit_error(void);
void	no_int(char **newArgv);
int	atoinaitor(char **r, n_list **stack_a);
char	**parse(int argc, char **argv, n_list **stack_a); // Volvera a ser void al terminar las pruebas.

char	**clean_argv(char **argv, int argc);

int     lstadd_back(n_list **list, n_list *new_node);
int	value_exists(n_list *stack_a, int p);

n_list	*lstnew(int content);

#endif
