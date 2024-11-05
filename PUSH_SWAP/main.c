#include "push_swap.h"

void exit_error(void)
{
        ft_putstr_fd("Error", 1);
        exit(1);
}

char **parse(int argc, char **argv, n_list **stack_a)
{
        char **newArgv;
        int *index;

        newArgv = clean_argv(argv, argc);  // limpia la entrada 
        no_int(newArgv); // revisa que sean solo num validos
        create_nodes(newArgv, stack_a); //pasa las str a int y los agrega a la lista revisando que no esten repetidos
        index = make_index(newArgv);//  hace un array con los enteros 
        array_sort(index); // ordenamos el array 
                                // indexamos la lista
        return (newArgv);
}

int main(int argc, char **argv)
{
        char *line;
	char **revM;
	int i;
	n_list *stack_head = NULL;
	n_list **stack_a = &stack_head;
	
        if (argc <= 1)
                exit(1);
	i = 0;
	revM = parse (argc, argv, stack_a);
        while ((line = revM[i]) != NULL)
        {
                line = revM[i];
                printf("%s\n", line);
                free(line);
                ++i;
        }
        return (0);
}
