/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** array_1d_sum
*/
#include "../include/my.h"
#include "../include/call.h"

int array_1d_sum(const int *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
