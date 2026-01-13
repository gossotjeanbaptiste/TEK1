/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** array_1d_print_chars
*/
#include "../include/call.h"
#include "../include/my.h"

void array_1d_print_chars(const char *arr)
{
    int i = 0;

    while (arr[i] != '\0') {
        my_putchar(arr[i]);
        my_putchar('\n');
        i++;
    }
}
