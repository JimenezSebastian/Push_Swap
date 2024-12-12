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

void sort_five_or_less(n_list **stack_a, n_list **stack_b, int argc)
{
    while (argc > 3) // Mover los números más pequeños al stack B
    {
        int min_index = find_min_index(*stack_a);
        int stack_size = lst_size(*stack_a);

        if (min_index <= stack_size / 2)
            while (min_index-- > 0)
                (ra_rb(stack_a), write(1, "ra_rb\n", 7));
        else
            while (min_index++ < stack_size)
                (rra_rrb(stack_a), write(1, "rra_rrb\n", 9)); // Rotate hacia el final
        (pb(stack_a, stack_b), write(1, "pb\n", 4)); // Push número mínimo a stack B
        argc--;
    }
    sort_three(stack_a); 
    while (*stack_b) // Reintegra los números desde stack_b a stack_a
    {
        (pa(stack_a, stack_b), write(1, "pa\n", 4)); // Push desde B a A
        if ((*stack_a)->index > (*stack_a)->next->index)
            (sa_sb(stack_a), write(1, "sa_sb\n", 7)); // Asegura el orden después de insertar
    }
}

void sort_three(n_list **stack_a)
{
    int first = (*stack_a)->index;
    int second = (*stack_a)->next->index;
    int third = (*stack_a)->next->next->index;

    if (first > second && second < third && first < third)
        (sa_sb(stack_a), write(1, "sa_sb\n", 7));
    else if (first > second && second > third)
    {
        (sa_sb(stack_a), write(1, "sa_sb\n", 7));
        (rra_rrb(stack_a), write(1, "rra_rrb\n", 9));
    }
    else if (first > second && second < third && first > third)
        (rra_rrb(stack_a), write(1, "rra_rrb\n", 9));
    else if (first < second && second > third && first < third)
    {
        (sa_sb(stack_a), write(1, "sa_sb\n", 7));
        (ra_rb(stack_a), write(1, "ra_rb\n", 7));
    }
    else if (first < second && second > third && first > third)
		(rra_rrb(stack_a), write(1, "rra_rrb\n", 9));
}

