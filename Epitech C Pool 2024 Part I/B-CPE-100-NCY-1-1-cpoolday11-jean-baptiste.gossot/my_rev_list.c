/*
** EPITECH PROJECT, 2024
** my_rev_list
** File description:
** reverse all the element of a
** list for the list to be like
** this list[0] = list[n] and list[n] = list[0]
*/

#include "include/mylist.h"
#include "include/my.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *precedent = NULL;
    linked_list_t *actuel = *begin;
    linked_list_t *suivant = NULL;

    while (actuel != NULL) {
        suivant = actuel->next;
        actuel->next = precedent;
        precedent = actuel;
        actuel = suivant;
    }
    *begin = precedent;
}
