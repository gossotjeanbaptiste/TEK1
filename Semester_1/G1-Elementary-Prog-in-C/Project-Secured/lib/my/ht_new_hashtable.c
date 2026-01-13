/*
** EPITECH PROJECT, 2025
** Project-Secured
** File description:
** new_hashtable
*/

#include "hashtable.h"
#include <stddef.h>
#include <stdlib.h>


linked_list_t *init_linked_list(void)
{
    linked_list_t *new_list = malloc(sizeof(linked_list_t));

    if (new_list == NULL) {
        return NULL;
    }
    new_list->key = 0;
    new_list->value = NULL;
    new_list->next = NULL;
    return new_list;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (ht == NULL) {
        return NULL;
    }
    ht->lenght = len;
    ht->hash = hash;
    ht->element = malloc(sizeof(linked_list_t *) * len);
    if (ht->element == NULL) {
        return NULL;
    }
    for (int i = 0; i != len; i++) {
        ht->element[i] = init_linked_list();
    }
    return ht;
}
