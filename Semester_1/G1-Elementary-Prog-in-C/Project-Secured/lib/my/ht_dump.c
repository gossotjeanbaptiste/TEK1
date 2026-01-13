/*
** EPITECH PROJECT, 2025
** Project-Secured
** File description:
** ht_dump
*/

#include <unistd.h>
#include <string.h>
#include "hashtable.h"
#include "my.h"


void verif(unsigned long key, char *value, int index)
{
    if (key != 0 && value != NULL) {
        mini_printf("> %l - %s\n", key, value);
    }
}

void ht_dump(hashtable_t *ht)
{
    linked_list_t *current;

    for (int i = 0; i < ht->lenght; i++) {
        current = ht->element[i];
        mini_printf("[%d]:\n", i);
        while (current != NULL) {
            verif(current->key, current->value, i);
            current = current->next;
        }
    }
}
