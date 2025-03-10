/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured Bootstrap
** File description:
** bootstrap.h
*/

#ifndef BOOTSTRAP_H
    #define BOOTSTRAP_H

typedef struct entry_s {
    char *name;
    char *phone_number;
} entry_t;
entry_t **create_address_book(int len);
entry_t *create_address(const char *name, const char *phone_number);
void delete_address(entry_t *address);
#endif /* BOOTSTRAP_H */
