/*
** EPITECH PROJECT, 2024
** Project-Organized
** File description:
** sort
*/

#include "../include/my.h"
#include "../include/shell.h"

void *my_memcpy(void *dest, void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    while (n != 0 && d && s) {
        *d = *s;
        d++;
        s++;
        n--;
    }
    return dest;
}

int swap_mem(void *a, void *b, size_t size)
{
    void *temp = malloc(size);

    if (temp == NULL) {
        return 84;
    }
    my_memcpy(temp, a, size);
    my_memcpy(a, b, size);
    my_memcpy(b, temp, size);
    free(temp);
    return 0;
}

void bubble_sort(var_sort_t *var_sort, int (*cmp)(const void *, const void *))
{
    for (int i = var_sort->low; i < var_sort->high - 1; i++) {
        annexe_bubble_sort(var_sort, i, cmp);
    }
}

void annexe_bubble_sort(var_sort_t *var_sort, int i,
    int (*cmp)(const void *, const void *))
{
    void *elem1;
    void *elem2;

    for (int j = var_sort->low; j < var_sort->high - i - 1; j++) {
        elem1 = (char *)var_sort->data + j * var_sort->size;
        elem2 = (char *)var_sort->data + (j + 1) * var_sort->size;
        if (cmp(elem1, elem2) > 0) {
            swap_mem(elem1, elem2, var_sort->size);
        }
    }
}

int sort(void *data, char **args)
{
    int (*cmp)(const void *, const void *);
    int reverse = 0;

    if (args[1] && my_strcmp(args[1], "-r") == 0) {
        reverse = 1;
    }
    if (determine_comparator(args[0], reverse, &cmp) == 84) {
        return 84;
    }
    if (sort_by_field(data, cmp) == 84) {
        return 84;
    }
    return 0;
}
