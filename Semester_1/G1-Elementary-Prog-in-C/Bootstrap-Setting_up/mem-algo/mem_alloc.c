/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** mem_alloc
*/
#include "../include/my.h"
#include "../include/call.h"

char *mem_alloc(char const *a, char const *b)
{
    int len_a = my_strlen(a);
    int len_b = my_strlen(b);
    char *a_and_b_combine = malloc(sizeof(char) * (len_b + 1));
    int len_a_and_b = my_strlen(a_and_b_combine);

    for (int i = 0; i < len_a; i++) {
        a_and_b_combine[i] = a[i];
    }
    for (int i = 0; i < len_b; i++) {
        a_and_b_combine[len_a + i] = b[i];
    }
    a_and_b_combine[len_a_and_b] = '\0';
    return a_and_b_combine;
}
