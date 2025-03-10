/*
** EPITECH PROJECT, 2024
** Bootstrap-Organized
** File description:
** delete_in_list
*/
#include "../include/my.h"
#include "../include/bootstrap.h"
#include "../include/call.h"

void replacing(linked_list_t **begin, linked_list_t *current,
    linked_list_t *previous)
{
    if (previous == NULL) {
        *begin = current->next;
    } else {
        previous->next = current->next;
    }
}

void delete_in_list(linked_list_t **begin, void *ref,
    int (*cmp_fct)(void *data, void *ref))
{
    linked_list_t *current = *begin;
    linked_list_t *previous = NULL;
    void *ref_dec = ref;

    while (current != NULL) {
        if (current->data != NULL &&
        cmp_fct(current->data, ref_dec) == 0) {
            replacing(begin, current, previous);
            free(current);
        }
        previous = current;
        current = current->next;
    }
}
