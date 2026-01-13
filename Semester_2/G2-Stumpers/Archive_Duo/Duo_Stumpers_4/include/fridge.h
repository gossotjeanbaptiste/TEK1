/*
** EPITECH PROJECT, 2025
** crocus
** File description:
** graphic_art header
*/

#ifndef FRIDGE_H_
    #define FRIDGE_H_
    #define INGREDIENT_COUNT 8

typedef struct ingredient_s {
    char name[6];
    int quantity;
}ingredient_t;

void handle_make_command(const char *line);
void add_to_fridge(const char *line);

#endif /* FRIDGE_H_ */
