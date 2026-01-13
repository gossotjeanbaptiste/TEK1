/*
** EPITECH PROJECT, 2024
** Project-Organized
** File description:
** create_hardware
*/

#include "../include/my.h"
#include "../include/shell.h"

hardware_t *create_hardware(const char *type, const char *name, int id)
{
    hardware_t *new = malloc(sizeof(hardware_t));

    if (!new)
        return NULL;
    new->type = my_strdup(type);
    new->name = my_strdup(name);
    new->id = id;
    if (!new->type || !new->name) {
        free(new->type);
        free(new->name);
        free(new);
        return NULL;
    }
    return new;
}
