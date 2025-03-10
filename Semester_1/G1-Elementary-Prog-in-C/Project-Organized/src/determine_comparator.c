/*
** EPITECH PROJECT, 2025
** Project-Organized
** File description:
** determine_comparator
*/

#include "../include/my.h"
#include "../include/shell.h"

#include "../include/my.h"
#include "../include/shell.h"

int determine_comparator(const char *field, int reverse,
    int (**cmp)(const void *, const void *))
{
    if (my_strcmp(field, "ID") == 0) {
        *cmp = reverse ? compare_by_id_reverse : compare_by_id;
    } else
        return determine_comparator_annexe(field, reverse, cmp);
    return 0;
}

int determine_comparator_annexe(const char *field, int reverse,
    int (**cmp)(const void *, const void *))
{
    if (field[0] == 'N' && field[1] == 'A' &&
        field[2] == 'M' && field[3] == 'E') {
        *cmp = reverse ? compare_by_name_reverse : compare_by_name;
    } else if (field[0] == 'T' && field[1] == 'Y' &&
        field[2] == 'P' && field[3] == 'E') {
        *cmp = reverse ? compare_by_type_reverse : compare_by_type;
    } else {
        return 84;
    }
    return 0;
}
