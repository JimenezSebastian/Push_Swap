#include "push_swap.h"

void	clean_exit(t_list **stack, int *index, char **argv)
{
	if (stack || index || argv)
		free_V2(stack, index, argv);
	ft_putstr_fd("Error", 1);
	exit(1);
}

void	free_V2(t_list **stack, int *index, char **argv)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (stack && *stack)
	{
		temp = *stack;       
		*stack = (*stack)->next; 
		free(temp);
	}
	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			++i;
		}
		free(argv);
	}
	if (index)
	free(index);
}

void	overflow(char *str, int *index, char **argv)
{
	if (!str)
		clean_exit(NULL, index, argv);
	while (*str)
	{
		if (*str >= '1' && *str <= '9')
			clean_exit(NULL, index, argv);
		++str;
	}
}

int	verify(t_list *stack_a)
{
	int	save;

	save = -2147483648;
	while (stack_a)
	{
		if (stack_a->num < save)
			return (1);
		else
			save = stack_a->num;
		stack_a = stack_a->next;
	}
	return (0);
}

int	find_min_index(t_list *stack)
{
	int	min_index;
	int	min_value;
	int	current_index;

	min_index = 0;
	min_value = stack->index;
	current_index = 0;
	while (stack)
	{
		if (stack->index < min_value)
		{
			min_value = stack->index;
			min_index = current_index;
		}
		stack = stack->next;
		current_index++;
	}
	return (min_index);
}
