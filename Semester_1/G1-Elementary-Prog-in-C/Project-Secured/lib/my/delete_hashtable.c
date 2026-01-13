/*
** EPITECH PROJECT, 2025
** Project-Secured
** File description:
** delete_hashtable
*/

#include "hashtable.h"
#include "my.h"

void deletelist(linked_list_t *curr)
{
    if (curr == NULL) {
        return;
    }
    deletelist(curr->next);
    free(curr);
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL) {
        return;
    }
    for (int i = 0; i < ht->lenght; i++) {
        deletelist(ht->element[i]);
    }
    free(ht->element);
    free(ht);
}
