#include "../include/push_swap.h"

void	test(t_node *stack_a)
{
	while (stack_a)
	{
		printf("Num:%i\n", stack_a->num);
		stack_a = stack_a->next;
	}
}

void	tester_indx(int *index, int argc)
{
	printf("Testindex\n");
	while (argc-- >= 1)
		printf("t%i", *(index++));
	printf("\n");
}