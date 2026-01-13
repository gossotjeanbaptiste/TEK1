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
GRAPHIC_DIR = src/graphic_art
TOOLS_DIR = src/tools

SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/handle_specifier.c
TOOLS = $(TOOLS_DIR)/replace_char.c \
		$(TOOLS_DIR)/print_digit.c
GRAPHIC = $(GRAPHIC_DIR)/graph_zero.c \
		  $(GRAPHIC_DIR)/graph_one.c  \
		  $(GRAPHIC_DIR)/graph_two.c   \
		  $(GRAPHIC_DIR)/graph_three.c \
		  $(GRAPHIC_DIR)/graph_four.c  \
		  $(GRAPHIC_DIR)/graph_five.c  \
		  $(GRAPHIC_DIR)/graph_six.c   \
		  $(GRAPHIC_DIR)/graph_seven.c \
		  $(GRAPHIC_DIR)/graph_eight.c \
		  $(GRAPHIC_DIR)/graph_nine.c
 
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_T = $(TOOLS:$(TOOLS_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_G = $(GRAPHIC:$(GRAPHIC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = crocus

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_T) $(OBJ_G)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_T) $(OBJ_G)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: $(TOOLS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: $(GRAPHIC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
