/*
** EPITECH PROJECT, 2024
** Project-Organized
** File description:
** del
*/
#include "../include/my.h"
#include "../include/shell.h"

void delete_hardware(hardware_t *current, hardware_t *previous,
    void *data, int id)
{
    if (current->id == id) {
        replace(current, previous, data);
        mini_printf("%s n\u00b0%d - \"%s\" deleted.\n",
                    current->type, current->id, current->name);
        free(current);
        return;
    }
}

int is_number(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int find_and_delete(workshop_t *workshop, int id)
{
    hardware_t *current = workshop->head;
    hardware_t *previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            delete_hardware(current, previous, workshop, id);
            return 1;
        }
        previous = current;
        current = current->next;
    }
    return 0;
}

int del(void *data, char **args)
{
    workshop_t *workshop = (workshop_t *)data;
    int id;
    int found;

    if (validate_args(data, args) == 84)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        id = my_getnbr(args[i]);
        found = find_and_delete(workshop, id);
        if (!found)
            return 84;
    }
    return 0;
}

void replace(hardware_t *current, hardware_t *previous, void *data)
{
    if (previous == NULL)
        ((workshop_t *)data)->head = current->next;
    else
        previous->next = current->next;
}
