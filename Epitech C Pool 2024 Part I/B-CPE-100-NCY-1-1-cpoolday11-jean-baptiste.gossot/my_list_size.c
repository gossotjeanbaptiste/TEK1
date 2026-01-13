/*
** EPITECH PROJECT, 2024
** my_list_size
** File description:
** calculate the size of a list
*/

#include "include/mylist.h"
#include "include/my.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    while (begin != NULL) {
        begin = begin->next;
        i++;
    }
    return i;
}
