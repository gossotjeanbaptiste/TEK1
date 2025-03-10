/*
** EPITECH PROJECT, 2025
** Bootstrap-Secured
** File description:
** create_address
*/
#include "../include/bootstrap.h"
#include "../include/my.h"
#include <stdlib.h>

entry_t *create_address(const char *name, const char *phone_number)
{
    entry_t *address = malloc(sizeof(entry_t));

    if (address == NULL) {
        return NULL;
    }
    address->name= my_strdup(name);
    address->phone_number = my_strdup(phone_number);
    return address;
}
