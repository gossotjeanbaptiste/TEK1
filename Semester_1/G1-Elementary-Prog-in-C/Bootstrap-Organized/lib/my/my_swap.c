/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swap two int
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = a;
    a = b;
    b = a;
}
