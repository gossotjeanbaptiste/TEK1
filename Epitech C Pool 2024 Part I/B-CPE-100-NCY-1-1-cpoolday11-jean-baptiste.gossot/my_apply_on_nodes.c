/*
** EPITECH PROJECT, 2024
** my_apply_on_nodes
** File description:
** applies a function given as argument to the data of each nodes
*/
#include "include/mylist.h"
#include "include/my.h"
#include <stdlib.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *tmp = begin;

    while (tmp != NULL) {
        f(tmp->data);
        tmp = tmp->next;
    }
    return (0);
}
