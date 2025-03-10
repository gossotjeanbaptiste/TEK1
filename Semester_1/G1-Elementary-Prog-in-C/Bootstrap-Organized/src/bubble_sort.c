/*
** EPITECH PROJECT, 2024
** Bootstrap-Organized
** File description:
** bubble_sort
*/
#include "../include/my.h"
#include "../include/bootstrap.h"
#include "../include/call.h"

void bubble_sort(int *array, int len)
{
    for (int i = 0; i < (len - 1); i++) {
        for (int j = 0; j < (len - i - 1); j++) {
            compare_index(array, j);
        }
    }
}

void compare_index(int *array, int j)
{
    int temp;

    if (array[j] > array[j + 1]) {
        my_swap(array[j], array[j + 1]);
    }
}
