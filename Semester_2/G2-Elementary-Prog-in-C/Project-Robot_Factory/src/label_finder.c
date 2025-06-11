/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** label
*/
#include "../include/my.h"
#include "../include/corewar.h"
extern const op_t op_tab[];

char *label_finder(char line[MAX_LINE])
{
    char *label = line;
    char *label_ptr = my_strchr(line, ':');
    char *instruction_start = label_ptr + 1;

    if (label_ptr != NULL) {
        *label_ptr = '\0';
        label = line;
        mini_printf("Label found: %s\n", label);
        instruction_start = label_ptr + 1;
        while (*instruction_start == ' ') {
            instruction_start++;
        }
        my_strcpy(line, instruction_start);
        return label;
    }
    return NULL;
}
