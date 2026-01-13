/*
** EPITECH PROJECT, 2024
** rush 3
** File description:
** final stumper
*/
#include "include/my.h"
#include <unistd.h>
#include <stdio.h>

int rush3(char *buffer)
{
    int len_buffer = my_strlen(buffer);

    for (int i = 0; i < len_buffer; i++) {
        printf("%c", buffer[i]);
    }
    my_putchar("\n");
    return 0;
}
