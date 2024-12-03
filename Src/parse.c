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

#include "libft.h"
#include "push_swap.h"

void    index_lst(n_list **stack_a, int *nums)
{
	int	i;
	n_list	*ptr;
	
	ptr = *stack_a;
	while (ptr)
	{
		i = 0;
		while (ptr->num != nums[i])
			i++;
		ptr->index = i;
		ptr = ptr->next;
	}
}

void array_sort(int *nums, int size_array)
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
			break;
	}
}

int *make_index(char **newArgv, int size_array)
{
	char	*str;
        int	*i_array;
        int	i;

        i = 0;
        i_array = malloc(size_array * sizeof(int));
        if (!i_array)
                exit_error();
        while ((str = newArgv[i]) != NULL)
        {
		i_array[i] = ft_atoi(str);
                ++i;
        }
        return (i_array);
}

int n_atoi(char *str)
{
	char c;

	while ((c = *str))
	{
	 	ft_atoi(&c);
	}
	
}

void	create_nodes(char **r, n_list **stack_a)
{
	char *str;
	char c;
	int p;
	int i;
	n_list *new_node = NULL;

	i = 0;
	while ((str = r[i]) != NULL)
	{
		p = n_atoi(str);
		if (p >= INT_MIN && p <= INT_MAX)
		{
			if (value_exists(*stack_a, p))
				exit_error();
			new_node = lstnew(p);
			if (!new_node)
            			exit_error();
			lstadd_back(stack_a, new_node);
		}
		else
			exit_error();
		i++;
	}
}

int	no_int(char **newArgv)
{
	char	*str;
	int	size;
	int	i;
	int	s;

	i = 0;
	size = 0;
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
		++size;
	}
	return (size);
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
