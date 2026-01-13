/*
** EPITECH PROJECT, 2024
** Bootstrap-Organized
** File description:
** display_list
*/
#include "../include/my.h"
#include "../include/bootstrap.h"
#include "../include/call.h"

void display_list(linked_list_t *begin, void (*disp_fct)(void *data))
{
    linked_list_t *tmp = malloc(sizeof(linked_list_t *));

    tmp = begin;
    while (tmp != NULL) {
        disp_fct(tmp->data);
        tmp = tmp->next;
    }
}
