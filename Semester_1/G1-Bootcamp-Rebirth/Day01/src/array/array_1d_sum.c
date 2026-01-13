/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** array_1d_sum
*/

#include "../../include/my.h"

int array_1d_sum(int const *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
