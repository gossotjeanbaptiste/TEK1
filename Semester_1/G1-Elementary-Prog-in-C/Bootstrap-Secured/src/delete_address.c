/*
** EPITECH PROJECT, 2025
** Bootstrap-Secured
** File description:
** delete_address
*/
#include "../include/bootstrap.h"
#include "../include/my.h"
#include <stdlib.h>

void delete_address(entry_t *address)
{
    free(address->name);
    free(address->phone_number);
    free(address);
}