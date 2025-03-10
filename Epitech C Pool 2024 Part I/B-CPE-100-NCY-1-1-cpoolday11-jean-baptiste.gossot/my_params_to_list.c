/*
** EPITECH PROJECT, 2024
** my_params_to_list
** File description:
** create new list from command line args
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

linked_list_t *my_params_to_list(int ac, char const **av)
{
    linked_list_t *list = 0;
    linked_list_t *item = 0;

    for (int i = 0; i < ac; i++) {
        item = malloc(sizeof(linked_list_t));
        item->data = av[i];
        item->next = list;
        list = item;
    }
    return list;
}
