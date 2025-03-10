/*
** EPITECH PROJECT, 2025
** Project-my_sudo
** File description:
** init_var
*/
#include "../include/my_sudo.h"
#include "../include/my.h"


int initialize_var(var_t *var)
{
    var->euid = geteuid();
    var->passwd_file = fopen("/etc/passwd", "r");
    if (var->passwd_file == NULL) {
        perror("fopen");
        return 84;
    }
    return 0;
}
