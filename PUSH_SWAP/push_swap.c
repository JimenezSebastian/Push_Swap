#include "push_swap.h"
#include <math.h>

void radix_sort(n_list **stack_a, n_list **stack_b)
{
	int max_bits;
	int i;
	int size;
	int j;

	i = 0;
	max_bits = get_max_bits(*stack_a);
//	size = lst_size(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		size = lst_size(*stack_a);
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
			{
				pb(stack_a, stack_b);			// Mueve a B si el bit es 0
				write(1, "pb\n", 3);
			}
			else
			{
				ra_rb(stack_a);			// Rota en A si el bit es 1
				write(1, "ra\n", 3);
			}
			j++;
		}
		while (*stack_b)
		{
			pa(stack_a, stack_b);
			write(1, "pa\n", 3);
		}
        	i++;
	}
}

void parse(int argc, char **argv, n_list **stack_a)
{
        char	**newArgv;
        int	*nums;
	int	size_array;
	
        newArgv = clean_argv(argv, argc);
        size_array = no_int(newArgv);
        create_nodes(newArgv, stack_a);
        nums = make_index(newArgv, size_array);
	array_sort(nums, size_array);
        index_lst(stack_a, nums);
}

int main(int argc, char **argv)
{
	n_list	*stack_a = NULL;
	n_list	*stack_b = NULL;
	
        if (argc <= 1)
                exit(1);
	parse(argc, argv, &stack_a);
	radix_sort(&stack_a, &stack_b);
	while (stack_a)
        {
                printf("Num:%i\n", stack_a->num);
//              printf("%i", ->index);
                stack_a = stack_a->next;
        }
        return (0);
}
