/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** array_1d_print_ints
*/
#include "../include/call.h"
#include "../include/my.h"

void array_1d_print_ints(const int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        my_put_nbr(arr[i]);
        my_putchar('\n');
    }
}
