/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** trim_lead_whitespace
*/
#include "../include/my.h"
#include "../include/corewar.h"
extern const op_t op_tab[];

void trim_leading_whitespace(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    if (str[i] == '\0') {
        str[0] = '\0';
        return;
    }
    if (i > 0) {
        while (str[i] != '\0') {
            str[j] = str[i];
            i++;
            j++;
        }
        str[j] = '\0';
    }
}
