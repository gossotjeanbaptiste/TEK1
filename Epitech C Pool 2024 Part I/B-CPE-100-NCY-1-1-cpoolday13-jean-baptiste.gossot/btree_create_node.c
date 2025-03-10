/*
** EPITECH PROJECT, 2024
** btree_create_node
** File description:
** create nodes and initialize they're values
*/

#include "include/btree.h"
#include <stdlib.h>

btree_t *btree_create_node(void *item)
{
    int node = malloc(sizeof(item));
    
    node = item;
    return node;
}
    
