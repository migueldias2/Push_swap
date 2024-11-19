# Program name
NAME = push_swap

# Source files
SRC = main.c split.c  \
		atol_duplicated_add_a.c \
		quicksort.c sort_rotate.c \
		sort3.c push_a.c movements_a.c \
		find_top_bottom.c print_stack.c \
		sort_all_aux.c handle_invalid.c \


# Object files
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default rule to build the program
all: $(NAME)

# Link object files and create executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compile .c files into .o (object) files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
