#include "push_swap.h"

void exit_error(void)
{
        ft_putstr_fd("Error", 1);
        exit(1);
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
