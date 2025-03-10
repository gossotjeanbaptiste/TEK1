/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** display if an integer is positive or negative
*/
#include "my.h"

void my_isneg(int n)
{
    if (n < 0){
        my_putchar('N');
        my_putchar('\n');
    } else {
        my_putchar('P');
        my_putchar('\n');
    }
}
