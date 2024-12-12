#include "push_swap.h"

void test(n_list *stack_a)
{
	while (stack_a)
    {
        printf("Num:%i\n", stack_a->num);
	//	printf("Index:%i\n", stack_a->index);
		stack_a = stack_a->next;
    }
}
void tester_indx(int *index, int argc)
{
	printf("Testindex\n");
	while (argc-- >= 1)
		printf("t%i", *(index++));
	printf("\n");
}

int parse(int argc, char **argv, n_list **stack_a)
{
        int		*index;

        argv = cleaner_argv(argv, argc);
        argc = digits_checker(argv);
		index = make_index(argv, argc);
        node_indexer_creator(stack_a, index, argc);
		return (free(index), argc);
}

int main(int argc, char **argv)
{
	n_list	*stack_a = NULL;
	n_list	*stack_b = NULL;

    if (argc < 2)
		exit(1);
	argc = parse(argc, argv, &stack_a);
	if (argc <= 5)
		sort_five_or_less(&stack_a, &stack_b, argc);	
	algorithm(&stack_a, &stack_b);
	test(stack_a);
	return (0);
}