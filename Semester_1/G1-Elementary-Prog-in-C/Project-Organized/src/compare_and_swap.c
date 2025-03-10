/*
** EPITECH PROJECT, 2025
** Project-Organized
** File description:
** compare_and_swap
*/
#include "../include/my.h"
#include "../include/shell.h"

int swap_elements(char *arr, int i, int j, size_t size)
{
    return swap_mem(arr + i * size, arr + j * size, size);
}

int compare_and_swap(comp_and_swap_t *cas)
{
    void *element = cas->arr + cas->j * cas->size;

    if (cas->cmp(element, cas->pivot) < 0) {
        (*cas->i)++;
        if (cas->swap_elements(cas->arr, *cas->i, cas->j, cas->size) == 84) {
            return 84;
        }
    }
    return 0;
}
