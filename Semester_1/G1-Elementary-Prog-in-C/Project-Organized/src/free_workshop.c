/*
** EPITECH PROJECT, 2025
** Project-Organized
** File description:
** free_workshop
*/
#include "../include/my.h"
#include "../include/shell.h"

void free_workshop(workshop_t *workshop)
{
    hardware_t *current = workshop->head;
    hardware_t *next;

    while (current != NULL) {
        next = current->next;
        free(current->type);
        free(current->name);
        free(current);
        current = next;
    }
}
