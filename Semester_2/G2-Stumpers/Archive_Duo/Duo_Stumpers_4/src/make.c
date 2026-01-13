/*
** EPITECH PROJECT, 2025
** make command
** File description:
** DESCRIPTION
*/

#include <string.h>
#include <stdio.h>
#include "../include/fridge.h"

extern ingredient_t ingredients[INGREDIENT_COUNT];

static void check_quantity(int quantity, int index, const char *name)
{
    if (ingredients[index].quantity >= quantity)
        ingredients[index].quantity -= quantity;
    else
        printf("'make %s': not enough %s\n", name, ingredients[index].name);
}

void handle_make_command(const char *line)
{
    int quantity_pizza[INGREDIENT_COUNT] = {5, 1, 3, 0, 8, 8, 4, 3};
    int quantity_pasta[INGREDIENT_COUNT] = {5, 0, 0, 2, 6, 0, 4, 3};

    if (strcmp("make pizza", line) == 0)
        for (int i = 0; i < INGREDIENT_COUNT; i++)
            check_quantity(quantity_pizza[i], i, "pizza");
    if (strcmp("make pasta", line) == 0)
        for (int i = 0; i < INGREDIENT_COUNT; i++)
            check_quantity(quantity_pasta[i], i, "pasta");
}
