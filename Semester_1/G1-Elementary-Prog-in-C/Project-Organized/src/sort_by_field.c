/*
** EPITECH PROJECT, 2025
** Project-Organized
** File description:
** sort_by_field
*/
#include "../include/my.h"
#include "../include/shell.h"

size_t get_list_count(hardware_t *list)
{
    size_t count = 0;
    hardware_t *current = list;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

hardware_t **create_array_from_list(hardware_t *list, size_t count)
{
    hardware_t **array = malloc(count * sizeof(hardware_t *));
    hardware_t *current = list;

    if (array == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < count; i++) {
        array[i] = current;
        current = current->next;
    }
    return array;
}

void update_list_from_array(workshop_t *workshop, hardware_t **array)
{
    hardware_t *current = workshop->head;
    int i = 0;

    while (current != NULL) {
        current = array[i];
        current = current->next;
        i++;
    }
}

int sort_by_field(workshop_t *workshop, int (*cmp)(const void *, const void *))
{
    size_t count = workshop->next_id;
    hardware_t **array = create_array_from_list(workshop->head, count);
    var_sort_t var_sort;

    if (array == NULL) {
        return 84;
    }
    var_sort.data = array;
    var_sort.low = 0;
    var_sort.high = count;
    var_sort.size = sizeof(hardware_t *);
    bubble_sort(&var_sort, cmp);
    update_list_from_array(workshop, array);
    free(array);
    return 0;
}
