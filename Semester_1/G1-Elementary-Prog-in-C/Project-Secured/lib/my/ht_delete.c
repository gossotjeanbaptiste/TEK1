/*
** EPITECH PROJECT, 2025
** Project-Secured
** File description:
** ht_delete
*/

#include "hashtable.h"


linked_list_t *find_node(linked_list_t *list, long key, linked_list_t **prev)
{
    linked_list_t *current = list;

    *prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        *prev = current;
        current = current->next;
    }
    return NULL;
}

int ht_delete(hashtable_t *ht, char *key)
{
    unsigned long hash_key = ht->hash(key, ht->lenght);
    int index = hash_key % ht->lenght;
    linked_list_t *list = ht->element[index];
    linked_list_t *prev = NULL;
    linked_list_t *node_del;

    node_del = find_node(list, hash_key, &prev);
    if (node_del == NULL) {
        return 84;
    }
    if (prev == NULL) {
        ht->element[index] = node_del->next;
    } else {
        prev->next = node_del->next;
    }
    free(node_del);
    return 0;
}
