/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** Main for Epi-Template-C
*/
#include "include/my.h"
#include "include/shell.h"

int main(void)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};

    if (workshop_shell(&workshop) != 0) {
        return 84;
    }
    free_workshop(&workshop);
    return 0;
}
