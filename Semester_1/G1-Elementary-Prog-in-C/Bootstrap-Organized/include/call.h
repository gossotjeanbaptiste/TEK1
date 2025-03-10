/*
** EPITECH PROJECT, 2024
** Bootstrap-Organized
** File description:
** call
*/
#include <stdlib.h>

#ifndef INCLUDED_CALL_H
    #define INCLUDED_CALL_H
int main(void);
void display_function(void *data);
int compare_function(void *data, void *ref);
int print_typed_value(void *data, type_t type);
void replacing(linked_list_t **begin, linked_list_t *current,
    linked_list_t *previous);
void delete_in_list(linked_list_t **begin, void *ref,
    int (*cmp_fct)(void *data, void *ref));
void push_to_list(linked_list_t **begin, void *data);
void display_list(linked_list_t *begin, void (*disp_fct)(void *data));
void bubble_sort(int *array, int len);
void compare_index(int *array, int j);
#endif
