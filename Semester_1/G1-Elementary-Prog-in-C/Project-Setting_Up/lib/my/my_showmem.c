/*
** EPITECH PROJECT, 2024
** my_showmem
** File description:
** show memory
*/
#include "my.h"
#include <ctype.h>
#include <unistd.h>



void annexe_to_my_showmem3(int i, char const *str, int size, char c)
{
    for (int j = 0; j < 16; j++) {
        if (i + j < size) {
            my_puthex2((unsigned char)str[i + j]);
            my_putstr(" ");
        } else {
            my_putstr("   ");
        }
    }
}

void annexe_to_my_showmem2(int i, char const *str, int size, char c)
{
    if (isprint((unsigned char)c)) {
        my_putchar(c);
    } else {
        my_putstr(".");
    }
}

void annexe_to_my_showmem(int i, char const *str, int size)
{
    char c = str[i];

    for (int j = 0; j < 16; j++) {
        if (i + j < size) {
            c = str[i + j];
            annexe_to_my_showmem2(i, str, size, c);
        } else {
            my_putstr(" ");
        }
    }
}

int my_showmem(char const *str, int size)
{
    for (int i = 0; i < size; i += 16) {
        my_puthex8(i);
        my_putstr(": ");
        annexe_to_my_showmem3(i, str, size, str[i]);
        my_putstr(" ");
        annexe_to_my_showmem(i, str, size);
        my_putstr("\n");
    }
    return 0;
}
