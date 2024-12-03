#include <stdio.h>

int get_max_bits(t_stack *stack)
{
    	int max;
	max = INT_MIN;
	t_stack *ptr = stack;
	while (ptr)
	{
		if (ptr->index > max)
			max = ptr->index;
		ptr = ptr->next;
	}
    	return (int)(log2(max)) + 1;  // Si los índices son positivos
}

void radix_sort(t_stack **stack_a, t_stack **stack_b) 
{
	int max_bits;
	int i;
	int size;
	int j;

	i = 0;
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		size = lst_size(*stack_a);
		j = 0;
		while (j < size) 
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		j++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
	i++;
	}
}

void array_sort(int *nums, int size)
{
        int     i;
        int     flag;
        int     temp;

	temp = 0;
        while (1)
        {
		i = 0;
                flag = 0;
                while (i < size - 1)
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

int main ()
{
	int nums[] = {4, 3, 2, 1};
	int size = 4;
	int i = 0;

	array_sort(nums, size);
	while (i < size)
	{
		printf("%d", nums[i]);
		++i;
	}
	return (0);
}
