#include "push_swap.h"

void algorithm(n_list **stack_a, n_list **stack_b)
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

int value_exists(n_list *stack_a, int p)
{
        n_list *temp;

        temp = stack_a;
        while (temp)
        {
                if ((int)temp->num == p)
                        return (1);
                temp = temp->next;
        }
        return (0);
}

void exit_error(void)
{
        ft_putstr_fd("Error", 1);
        exit(1);
}

n_list *lstnew(int content)
{
	n_list *newNode;

	newNode = malloc(sizeof(n_list));
	if (!newNode)
		return(NULL);
	newNode -> num = content;
	newNode -> next = NULL;
	return (newNode);
}

int lstadd_back(n_list **list, n_list *newNode)
{
	n_list *ptr;

	ptr = *list;
	if (!newNode)
		return(1);
	else if (!(*list))
	{
		*list = newNode;
		return(0);
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newNode;
	return (0);	
}

int lst_size(n_list *lst)
{
	int size;
	n_list *ptr;	
	
	ptr = lst;
	size = 0;
	while (ptr)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}

int get_max_bits(n_list *lst)
{
	int		max;
	n_list	*ptr;

	max = -2147483647;
	ptr = lst;
	while (ptr)
	{
		if (ptr->index > max)
			max = ptr->index;
		ptr = ptr->next;
	}

	return ((int)log2(max) + 1);
}

void    index_lst(n_list **stack_a, int *index)
{
	int		i;
	n_list	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		i = 0;
		while (ptr->num != index[i])
			i++;
		ptr->index = i;
		ptr = ptr->next;
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

char *ft_strcat(char *dest, const char *src)
{
    char *dest_copy = dest;

    // Mover el puntero de 'dest' hasta el final de la cadena
    while (*dest)
    {
        dest++;
    }

    // Copiar cada caracter de 'src' a 'dest'
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    // Terminar la cadena 'dest' con el carácter nulo '\0'
    *dest = '\0';

    return (dest_copy);  // Devolver la cadena original 'dest'
}