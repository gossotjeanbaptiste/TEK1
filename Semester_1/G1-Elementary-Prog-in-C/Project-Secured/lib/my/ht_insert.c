/*
** EPITECH PROJECT, 2025
** Project-Secured
** File description:
** ht_insert
*/

#include "hashtable.h"
#include "my.h"
#include <stddef.h>
#include <stdlib.h>

linked_list_t *create_node(unsigned long hash_key, char *value)
{
    linked_list_t *newNode = malloc(sizeof(linked_list_t));

    if (newNode == NULL) {
        return NULL;
    }
    newNode->value = value;
    newNode->key = hash_key;
    newNode->next = NULL;
    return newNode;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    unsigned long hash_key = ht->hash(key, ht->lenght);
    int index = hash_key % ht->lenght;
    linked_list_t *current = ht->element[index];
    linked_list_t *newNode = NULL;

    while (current != NULL){
        if (current->key == 0 && current->value == NULL) {
            current->key = hash_key;
            current->value = value;
            return 0;
        }
        if (current->next == NULL) {
            newNode = create_node(hash_key, value);
            current->next = newNode;
            return 0;
        }
        current = current->next;
    }
}
