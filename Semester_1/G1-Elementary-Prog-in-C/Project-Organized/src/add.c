/*
** EPITECH PROJECT, 2024
** Project-Organized
** File description:
** add
*/
#include "../include/my.h"
#include "../include/shell.h"

int verified(char *value)
{
    char *tab[] = {"ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", NULL};

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(value, tab[i]) == 0) {
            return 0;
        }
    }
    return 84;
}

int add(void *data, char **args)
{
    workshop_t *workshop = (workshop_t *)data;
    int ret_val;

    if (!args || !args[0]) {
        return 84;
    }
    for (int i = 0; args[i]; i += 2) {
        ret_val = adding(args, i, workshop);
        if (ret_val != 0)
            return ret_val;
    }
    return 0;
}

int adding(char **args, int i, workshop_t *workshop)
{
    hardware_t *new;

    if ((args[i] != NULL && args[i + 1] != NULL) && verified(args[i]) == 0) {
        new = create_hardware(args[i], args[i + 1], workshop->next_id);
        if (new == NULL) {
            return 84;
        }
        new->next = workshop->head;
        mini_printf("%s n\u00b0%d - \"%s\" added.\n",
                    args[i], workshop->next_id, args[i + 1]);
        workshop->head = new;
        workshop->next_id++;
    } else {
        return 84;
    }
    return 0;
}
