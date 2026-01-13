/*
** EPITECH PROJECT, 2025
** Project-Organized
** File description:
** compare_reverse
*/
#include "../include/my.h"
#include "../include/shell.h"

int compare_by_id_reverse(const void *a, const void *b)
{
    const hardware_t *ha = *(const hardware_t **)a;
    const hardware_t *hb = *(const hardware_t **)b;

    return hb->id - ha->id;
}

int compare_by_name_reverse(const void *a, const void *b)
{
    return compare_by_name(b, a);
}

int compare_by_type_reverse(const void *a, const void *b)
{
    return compare_by_type(b, a);
}
