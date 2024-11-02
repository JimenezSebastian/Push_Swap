NAME = push_swap.a

CC = cc
FLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SOURCES = $(wildcard *.c)
OBJ = $(SOURCES:.c=.o)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "Libreria $(NAME) creada."

all: $(NAME)

clean: 
	@$(RM) $(OBJ)
	 @echo "Archivos objeto eliminados."

fclean: clean 
	@$(RM) $(NAME)
	@echo "Archivos objeto y .a eliminados."

re: fclean all

.PHONY: all clean fclean re
