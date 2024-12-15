/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:30:56 by almejia-          #+#    #+#             */
/*   Updated: 2024/11/22 17:45:06 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **cleaner_argv(char **argv, int argc)
{
	char    **result;
	char    *new;
    int     total_length;
    int     i;

    i = 1;
	total_length = 0;
    while (i < argc)
        total_length += ft_strlen(argv[i++]) + 1;
    new = malloc(total_length);
    if (!new)
		clean_exit(NULL, NULL, NULL);
    new[0] = '\0';
    i = 1;
    while (i < argc)
    {
        ft_strcat(new, argv[i]);
        if (i++ < argc - 1)
            ft_strcat(new, " ");
    }
    result = ft_split(new, ' ');
	free(new);
	if (!result)
		clean_exit(NULL, NULL, NULL);
    return (result);
}

int digits_checker(char **argv)
{
	char	*str;
	int		size;
	int		s;

	size = 0;
	while((str = argv[size]) != NULL)
	{
		s = 0;
		while (str[s])
		{
			if ((str[s] >= '0' && str[s] <= '9') || str[s] == ' ')
				++s;
			else if (str[s] == '+' && str[s + 1] >= '0' && str[s + 1] <= '9')
				++s;
			else if (str[s] == '-' && str[s + 1] >= '0' && str[s + 1] <= '9')
				++s;
			else 
				clean_exit(NULL, NULL, argv);
		}
		++size;
	}
	return (size);
}

int *make_index(char **argv, int argc)
{
    int		*index;
    int		i;

    i = 0;
	index = malloc(argc * sizeof(int));
	if (!index)
		clean_exit(NULL, NULL, argv);
	while (argv[i])
    {
		index[i] = ft_atoi(argv[i]);
		if (index[i] == 0)
			overflow(argv[i], index, argv);
        ++i;
    }
    return (index);
}

void stack_generator(t_list **stack_a, int *index, int argc, char **argv)
{
	int		i;
	int		cpy;
	t_list	*new_node;

	i = 0;
	new_node = NULL;
	cpy = argc;
	while (cpy-- >= 1)
	{
		if (value_exists(*stack_a, index[i]))
			clean_exit(stack_a, index, argv);
		new_node = lstnew(index[i]);
		if (!new_node)
            clean_exit(stack_a, index, argv);
		lstadd_back(stack_a, new_node);
		i++;
	}
	array_sort(index, argc);
	index_lst(stack_a, index);
}
