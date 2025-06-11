/*
** EPITECH PROJECT, 2025
** addToFridge
** File description:
** DESCRIPTION
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/fridge.h"

extern ingredient_t ingredients[INGREDIENT_COUNT];

static int is_number(const char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] < '0' || line[i] > '9')
            return 0;
    return 1;
}

void add_to_fridge(const char *line)
{
    int len = 0;

    for (int i = 0; i < INGREDIENT_COUNT; i++) {
        len = strlen(ingredients[i].name);
        if (!strncmp(line + 12, ingredients[i].name, len) &&
            is_number(line + 12 + len + 1)) {
            ingredients[i].quantity += atoi(line + 12 + len + 1);
            return;
        }
    }
    printf("'%s': Invalid operation\n", line);
}
