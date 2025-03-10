/*
** EPITECH PROJECT, 2025
** Project-Secured
** File description:
** hash
*/

#include "hashtable.h"
#include "my.h"

unsigned long hash(char *key, int len)
{
    int hash_value = 5381;
    int c;

    while (*key) {
        *key++;
        c = *key;
        hash_value = ((hash_value << 5) + hash_value) + c;
    }
    if (hash_value < 0) {
        hash_value = hash_value * -1;
    }
    return (unsigned long)hash_value;
}
