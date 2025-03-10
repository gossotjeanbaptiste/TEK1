/*
** EPITECH PROJECT, 2025
** Project-Organized
** File description:
** compare
*/
#include "../include/my.h"
#include "../include/shell.h"

int compare_by_id(const void *a, const void *b)
{
    const hardware_t *ha = *(const hardware_t **)a;
    const hardware_t *hb = *(const hardware_t **)b;

    return hb->id - ha->id;
}

int compare_by_name(const void *a, const void *b)
{
    const hardware_t *ha = *(const hardware_t **)a;
    const hardware_t *hb = *(const hardware_t **)b;

    return my_strcmp(ha->name, hb->name);
}

int compare_by_type(const void *a, const void *b)
{
    const hardware_t *ha = *(const hardware_t **)a;
    const hardware_t *hb = *(const hardware_t **)b;

    return my_strcmp(ha->type, hb->type);
}
