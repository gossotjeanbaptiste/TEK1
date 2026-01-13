/*
** EPITECH PROJECT, 2024
** Bootstrap-Organized
** File description:
** push_to_list
*/
#include "../include/bootstrap.h"
#include "../include/my.h"
#include "../include/call.h"

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));
    linked_list_t *tmp = *begin;

    if (new == NULL)
        return;
    new->data = data;
    new->next = NULL;
    if (*begin == NULL) {
        *begin = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}
