/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** main
*/

#include "../include/fridge.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

ingredient_t ingredients[INGREDIENT_COUNT] = {
    {"tomato", 50},
    {"dough", 50},
    {"onion", 50},
    {"pasta", 50},
    {"olive", 50},
    {"pepper", 50},
    {"ham", 50},
    {"cheese", 50}
};

static int verif_line_content(int len_line, const char *line)
{
    for (int i = len_line; line[i] != '\n'; i++) {
        if (line[i] == '-')
            return -1;
        if (!isdigit(line[i]))
            return -1;
    }
    return 0;
}

static int valid_ingredient(const char *ingredient, const char *line)
{
    if (strncmp(ingredient, line, strlen(ingredient)) != 0)
        return -1;
    return 0;
}

static int initialize_ingredients(FILE *file)
{
    char *line = NULL;
    size_t n = 0;
    int count = 0;
    int len_line = 0;
    char s_line[10];

    while (getline(&line, &n, file) != -1) {
        if (count > 9)
            return -1;
        len_line = sprintf(s_line, "%s = ", ingredients[count].name);
        if (verif_line_content(len_line, line) ||
            valid_ingredient(s_line, line))
            return -1;
        count++;
    }
    return 0;
}

static void disp(void)
{
    for (int i = 0; i < INGREDIENT_COUNT; i++)
        printf("%s = %i\n", ingredients[i].name, ingredients[i].quantity);
}

static int handle_commands(const char *line)
{
    if (strncmp("exit", line, 4) == 0)
        return -1;
    if (strcmp("disp fridge", line) == 0) {
        disp();
        return 0;
    }
    if (strncmp("make", line, 4) == 0)
        handle_make_command(line);
    if (strncmp("addToFridge", line, 11) == 0)
        add_to_fridge(line);
    if (strncmp("addToFridge", line, 11) ||
        strncmp("make", line, 4))
        printf("'%s': Invalid operation\n", line);
    return 0;
}

int main(void)
{
    FILE *file = fopen(".save", "a+");
    char *line = NULL;
    size_t len = 0;

    if (!file)
        return 84;
    if (initialize_ingredients(file) == -1)
        return 84;
    while (1) {
        getline(&line, &len, stdin);
        line[strlen(line) - 1] = '\0';
        if (handle_commands(line))
            break;
    }
    fclose(file);
    free(line);
    return 0;
}
