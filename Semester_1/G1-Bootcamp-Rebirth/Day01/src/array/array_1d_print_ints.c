/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** array_1d_print_ints
*/
#include "../../include/my.h"

void array_1d_print_ints(int const *arr, int size)
{
    for (int i = 0; i < size; i++) {
        mini_printf("%d\n", arr[i]);
    }
}
