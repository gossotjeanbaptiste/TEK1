/*
** EPITECH PROJECT, 2025
** Project-Organized
** File description:
** partition
*/
#include "../include/my.h"
#include "../include/shell.h"

int annexe_partition(var_sort_t *var_sort_t, char *arr, int i,
    int (*cmp)(const void *, const void *))
{
    void *pivot = arr + var_sort_t->high * var_sort_t->size;
    comp_and_swap_t *cas = malloc(sizeof(comp_and_swap_t));

    if (cas == NULL)
        return 84;
    for (int j = var_sort_t->low; j < var_sort_t->high; j++) {
        cas->arr = arr;
        cas->pivot = pivot;
        cas->i = &i;
        cas->j = j;
        cas->size = var_sort_t->size;
        cas->cmp = cmp;
        cas->swap_elements = swap_elements;
        if (compare_and_swap(cas) == 84) {
            free(cas);
            return 84;
        }
    }
    free(cas);
    return 0;
}

int partition(struct var_sort *var_sort_t,
    int (*cmp)(const void *, const void *))
{
    char *arr = var_sort_t->data;
    int i = var_sort_t->low - 1;

    if (annexe_partition(var_sort_t, arr, i, cmp) == 84)
        return 84;
    if (swap_elements(arr, i + 1, var_sort_t->high, var_sort_t->size) == 84)
        return 84;
    return i + 1;
}
