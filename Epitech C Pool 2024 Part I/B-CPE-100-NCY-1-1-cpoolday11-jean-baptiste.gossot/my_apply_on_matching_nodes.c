/*
** EPITECH PROJECT, 2024
** my_apply_on_matching_nodes
** File description:
** applies a function given as argument
*/
#include "include/mylist.h"
#include "include/my.h"
#include <stdlib.h>

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(void *),
    void *data_ref, int (*cmp)())
{
    linked_list_t *tmp = begin;

    while (tmp != NULL) {
        if (cmp(tmp->data, data_ref) == 0)
            f(tmp->data);
        tmp = tmp->next;
    }
    return (0);
}
