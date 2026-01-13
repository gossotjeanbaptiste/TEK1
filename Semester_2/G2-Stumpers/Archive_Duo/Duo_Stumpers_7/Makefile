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

SRC = $(SRC_DIR)/main.c 			\
	  $(SRC_DIR)/get_random_word.c 	\
	  $(SRC_DIR)/get_word_list.c 	\
	  $(SRC_DIR)/play_round.c 		\
	  $(SRC_DIR)/read_guess.c 		\
	  $(SRC_DIR)/realloc_list.c 	\
	  $(SRC_DIR)/free_word_list.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = lingo

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
	rm -f src/*~
	rm -f coding-style-reports.log

re: fclean all

cs: fclean
	coding-style . .
	cat coding-style-reports.log
	rm -f coding-style-reports.log

.PHONY: all clean fclean re
