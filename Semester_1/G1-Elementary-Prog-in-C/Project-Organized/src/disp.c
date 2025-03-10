/*
** EPITECH PROJECT, 2024
** Project-Organized
** File description:
** disp
*/
#include "../include/my.h"
#include "../include/shell.h"

int disp(void *data, char **args __attribute__((unused)))
{
    workshop_t *workshop = (workshop_t *)data;
    hardware_t *current = workshop->head;

    while (current != NULL) {
        mini_printf("%s n\u00b0%d - \"%s\"\n",
        current->type, current->id, current->name);
        current = current->next;
    }
    return 0;
}
