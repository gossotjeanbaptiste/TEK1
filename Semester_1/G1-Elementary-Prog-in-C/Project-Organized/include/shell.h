/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
typedef struct hardware {
    char *type;
    char *name;
    int id;
    struct hardware *next;
} hardware_t;
typedef struct workshop {
    hardware_t *head;
    int next_id;
} workshop_t;

// * Adding functions
int add(void *data, char **args);
int adding(char **args, int i, workshop_t *workshop);
int verified(char *value);
hardware_t *create_hardware(char const *type, char const *name, int id);

// * Deleting functions
int del(void *data, char **args);
void replace(hardware_t *current, hardware_t *previous, void *data);
int validate_args(void *data, char **args);
void delete_hardware(hardware_t *current, hardware_t *previous,
    void *data, int id);
int is_number(const char *str);
int find_and_delete(workshop_t *workshop, int id);

// * Sorting functions
typedef struct var_sort {
    void *data;
    int low;
    int high;
    size_t size;
} var_sort_t;
typedef struct comp_and_swap_s {
    char *arr;
    void *pivot;
    int *i;
    int j;
    size_t size;
    int (*cmp)(const void *, const void *);
    int (*swap_elements)(char *, int, int, size_t);
} comp_and_swap_t;
int sort(void *data, char **args);
int compare_by_id(const void *a, const void *b);
int compare_by_id_reverse(const void *a, const void *b);
int compare_by_name(const void *a, const void *b);
int compare_by_name_reverse(const void *a, const void *b);
int compare_by_type(const void *a, const void *b);
int compare_by_type_reverse(const void *a, const void *b);
int determine_comparator(const char *field, int reverse,
    int (**cmp)(const void *, const void *));
int determine_comparator_annexe(const char *field, int reverse,
    int (**cmp)(const void *, const void *));
int sort_by_field(workshop_t *workshop,
    int (*cmp)(const void *, const void *));
void update_list_from_array(workshop_t *workshop, hardware_t **array);
hardware_t **create_array_from_list(hardware_t *list, size_t count);
size_t get_list_count(hardware_t *list);
int compare_and_swap(comp_and_swap_t *cas);
int swap_elements(char *arr, int i, int j, size_t size);
int swap_mem(void *a, void *b, size_t size);
void *my_memcpy(void *dest, void *src, size_t n);
void bubble_sort(var_sort_t *var_sort, int (*cmp)(const void *, const void *));
void annexe_bubble_sort(var_sort_t *var_sort, int i,
    int (*cmp)(const void *, const void *));

// * Display functions
int disp(void *data, char **args __attribute__((unused)));

// * Main function
int main(void);

// * Already implemented
int workshop_shell(void *data);
void free_workshop(workshop_t *workshop);
#endif /* SHELL_H */
