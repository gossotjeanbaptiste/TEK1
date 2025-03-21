/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <stddef.h>
    #include <unistd.h>
    #include <inttypes.h>
    #include <stdarg.h>
    #include <stdlib.h>

typedef struct linked_list_s {
    unsigned long key;
    char *value;
    struct linked_list_s *next;
}linked_list_t;

typedef struct hashtable_s {
    linked_list_t **element;
    int lenght;
    int (*hash)(char *, int);
} hashtable_t;

// Hash function
unsigned long hash(char *key, int len);

// Create & destroy table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
#endif /* HASHTABLE_H */
