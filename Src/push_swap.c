#include "push_swap.h"

void test(n_list stack_a)
{
	while (stack_a)
    {
        printf("Num:%i\n", stack_a->num);
		printf("Index:%i\n", stack_a->index);
		stack_a = stack_a->next;
    }
}

void parse(int argc, char **argv, n_list **stack_a)
{
        int		*index;

		// Argv limpio
        argv = cleaner_argv(argv, argc);
		//Argc limpio / verificar que todos son digitos en argv.
        argc = digits_checker(argv); 
		//Crear array ordenado(indice ideal).
		index = make_index(argv, argc);
		//Crear, agregar e indexar nodos en lista.
        node_indexer_creator(argv, stack_a, index);
}

int main(int argc, char **argv)
{
	n_list	*stack_a = NULL;
	n_list	*stack_b = NULL;
	
    if (argc < 2)
		exit(1);
	parse(argc, argv, &stack_a);
	algorithm(&stack_a, &stack_b);
	test(stack_a);
    return (0);
}
