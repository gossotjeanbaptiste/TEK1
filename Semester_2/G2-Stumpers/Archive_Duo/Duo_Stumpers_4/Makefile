##
## EPITECH PROJECT, 2025
## HEAD STUMPER
## File description:
## Reproduce the behavior of the head shell function
##

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
OBJ_DIR = obj

SRC = $(SRC_DIR)/main.c 	\
	  $(SRC_DIR)/add_to_fridge.c 	\
	  $(SRC_DIR)/make.c 	\
	  $(SRC_DIR)/write_in_save_file.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = fridge

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
