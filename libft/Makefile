# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almejia- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 22:08:57 by almejia-          #+#    #+#              #
#    Updated: 2024/05/05 08:58:06 by almejia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la biblioteca
NAME = libft.a

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Directorios
SRCDIR = src
OBJDIR = obj
INCDIR = includes

# Colores
CYAN = \033[0;96m
RED = \033[0;91m
DEF_COLOR = \033[0;49m

# Archivos fuente y objetos
SRCS = $(addprefix $(SRCDIR)/, ft_memset.c ft_bzero.c ft_strlen.c ft_atoi.c ft_isdigit.c \
	ft_isalpha.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_memchr.c ft_memcpy.c \
	ft_memcmp.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
	ft_strncmp.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_strrchr.c ft_calloc.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_split.c ft_striteri.c ft_strcat.c)
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:$(SRCDIR)/%.c=%.o))
DEP = $(OBJ:.o=.d)

# Objetivo principal
all: $(NAME)

# Crear la biblioteca estática
$(NAME): $(OBJ)
	@echo "$(CYAN) ☕ COMPILANDO LIBRERÍA... ☕ $(DEF_COLOR)"
	ar rcs $(NAME) $(OBJ)
	@echo "$(CYAN) ✨ ¡LIBRERÍA CREADA CON ÉXITO! ✨ $(DEF_COLOR)"

# Regla para compilar archivos .o desde .c
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Regla para limpiar archivos compilados
clean:
	@echo "$(CYAN) 🍩 ¡ELIMINANDO ARCHIVOS OBJETOS! 🍩 $(DEF_COLOR)"
	$(RM) $(OBJDIR)

# Regla para limpiar todo, incluyendo la librería
fclean: clean
	@echo "$(CYAN) ✨ ¡ELIMINANDO TODO! ✨ $(DEF_COLOR)"
	$(RM) $(NAME)

# Regla para recompilar todo
re: fclean all

# Regla para pruebas
TEST_SRCS = tests/test_main.c
TEST_NAME = tests.out
test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRCS) -I$(INCDIR) -L. -lft -o $(TEST_NAME)
	./$(TEST_NAME)

# Regla para depuración
debug: CFLAGS += -g
debug: re

# Dependencias automáticas
-include $(DEP)

%.d: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -MM $< -MF $@

# Variables especiales
.PHONY: all clean fclean re test debug
