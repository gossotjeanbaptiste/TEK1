/*
** EPITECH PROJECT, 2025
** Project-Secured
** File description:
** ht_search
*/

#include "hashtable.h"
#include "../my/my.h"

char *ht_search(hashtable_t *ht, char *key)
{
    unsigned long hash_key = ht->hash(key, ht->lenght);
    int index = hash_key % ht->lenght;
    linked_list_t *list = ht->element[index];

    while (list != NULL) {
        if (list->key == hash_key) {
            return list->value;
        }
        list = list->next;
    }
    return NULL;
}
