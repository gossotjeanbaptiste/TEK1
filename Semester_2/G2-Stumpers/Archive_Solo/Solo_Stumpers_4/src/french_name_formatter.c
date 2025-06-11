/*
** EPITECH PROJECT, 2025
** solo_stumper4
** File description:
** french_name_formatter
*/

#include "../include/my.h"

void french_name_formatter(char *str)
{
    int len = my_strlen(str);
    int i = 0;

    while (str[i] != ' ') {
        if (i == 0 && (str[i] >= 'a' && str[i] <= 'z')) {
                my_putchar(str[i] - 32);
        } else {
            print_part_name(str, i);
        }
        if (str[i] == '-' && (str[i + 1] >= 'a' && str[i + 1] <= 'z')) {
            i++;
        }
        i++;
    }
    print_family_name(str, i);
}

void print_part_name(char *str, int i)
{
    if (i != 0 && (str[i - 1] != '-' &&
        str[i] >= 'A' && str[i] <= 'Z')) {
        my_putchar(str[i] + 32);
    } else if (i != 0 && (str[i] == '-' &&
        (str[i + 1] >= 'a' && str[i + 1] <= 'z'))) {
        my_putchar(str[i]);
        my_putchar(str[i + 1] - 32);
        i++;
    } else {
        my_putchar(str[i]);
    }
}

void print_family_name(char *str, int i)
{
    while (str[i] != '\0') {
        verif_family_name(str, i);
        i++;
    }
    my_putchar('\n');
}

void verif_family_name(char *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z') {
        my_putchar(str[i] - 32);
    } else if (str[i] == ' ' || (str[i] >= 'A' && str[i] <= 'Z')) {
        my_putchar(str[i]);
    }
}
