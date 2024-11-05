/* ************************************************************************** */
/*                                 i                                           */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:30:56 by almejia-          #+#    #+#             */
/*   Updated: 2024/11/05 14:13:13 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void array_sort(int *int_array)
{
	
}

int *make_index(char **newArgv, int index)
{
        int *iarray;
        int i;
        char *str;
        n_list *head;

        i = 0;
        head = *stack_a;
        iarray = malloc(index * (sizeof)int);
        if (!iarray)
                exit_error();
        while ((str = newArgv[i]) != NULL)
        {
                iarray[i] = ft_atoi(str);
                ++i;
        }
        i = 0;
        return (iarray);
}

int value_exists(n_list *stack_a, int p)
{
	n_list *temp = NULL;

	temp = stack_a;
	while (temp)
	{
		if ((int)temp->num == p)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int create_nodes(char **r, n_list **stack_a)
{
	char *str;
	int index;
	int p;
	int i;
	n_list *new_node = NULL;

	i = 0;
	while ((str = r[i]) != NULL)
	{
		p = ft_atoi(str);
		if (p >= INT_MIN && p <= INT_MAX)
		{
			if (value_exists(*stack_a, p))
				exit_error();
			new_node = lstnew(p);
			if (!new_node)
            			exit_error();
			lstadd_back(stack_a, new_node);
			++index;
		}
		else
			exit_error();
		i++;
	}
	return (index);	
}

void no_int(char **newArgv)
{
	int i = 0;
	int s = 0;
	char *str;

	while((str = newArgv[i]) != NULL)
	{
		s = 0;
		while (str[s])
		{
			if (str[s] >= '0' && str[s] <= '9' || str[s] == ' ')
				++s;
			else if (str[s] == '+' && str[s + 1] >= '0' && str[s + 1] <= '9')
				++s;
			else if (str[s] == '-' && str[s + 1] >= '0' && str[s + 1] <= '9')
				++s;
			else 
				exit_error();
		}
		++i;
	}
	printf("Success\n");
}

char **clean_argv(char **argv, int argc)
{
	char	**result;
	char 	*temp;
	char	*str;
	char	*aux;
	int	i;

	str = ft_strjoin(argv[1], " ");
	i = 2;
	while(argc-- > 2)
	{
		temp = ft_strjoin(argv[i], " ");
		aux = ft_strjoin(str, temp);
		free(str);
                free(temp);
		str = aux;
		i++;
	}
	result = ft_split(str, ' ');
	free(str);
	return(result);
}
