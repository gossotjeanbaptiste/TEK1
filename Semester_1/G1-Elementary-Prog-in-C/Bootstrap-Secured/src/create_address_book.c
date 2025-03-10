/*
** EPITECH PROJECT, 2025
** Bootstrap-Secured
** File description:
** create_address_book
*/

#include "../include/my.h"
#include "../include/bootstrap.h"
#include <stdlib.h>

entry_t **create_address_book(int len)
{
    entry_t *address_book = malloc(sizeof(entry_t *) * len);
    int len_msg = 0;
    char *failed_message = "Malloc failed, address book couldn't be created";

    if (address_book == NULL) {
        len_msg = my_strlen(failed_message);
        write(2, failed_message, len_msg);
        return NULL;
    }
    for (int i = 0; i <= len; i++) {
        address_book->name = NULL;
        address_book->phone_number= NULL;
    }
    mini_printf("address book created");
    return &address_book;
}
