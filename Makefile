# Program name
NAME = push_swap

# Source files
SRC = main.c split.c aux_1.c aux_2.c aux_3.c \
	aux_4.c aux_5.c aux_6.c aux_7.c aux_8.c \
	aux_4_5.c aux_5_5.c

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
