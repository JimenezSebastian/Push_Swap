#include "push_swap.h"

void algorithm(n_list **stack_a, n_list **stack_b)
{
	int max_bits;
	int i;
	int size;
	int j;

	i = 0;
	(void)max_bits; 
	//  max_bits = get_max_bits(*stack_a);
//	size = lst_size(*stack_a);
	while (verify(*stack_a)) // i < max_bits;
	{
		j = 0;
		size = lst_size(*stack_a);
//		printf("%i", max_bits);
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
			{
				pb(stack_a, stack_b);
				write(1, "pb\n", 3);
			}
			else
			{
				ra_rb(stack_a);
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