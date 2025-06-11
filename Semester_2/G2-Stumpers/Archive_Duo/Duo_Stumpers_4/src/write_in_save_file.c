/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** write in save file
*/

#include "../include/fridge.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern ingredient_t ingredients[INGREDIENT_COUNT];

int write_in_file(FILE *file)
{
    for (int i = 0; i < INGREDIENT_COUNT; i++) {
        fprintf(file, "%s = %d\n",
        ingredients[i].name, ingredients[i].quantity);
    }
    return 0;
}
