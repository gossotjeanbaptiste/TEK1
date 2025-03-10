/*
** EPITECH PROJECT, 2025
** Bootstrap-My_Sudo
** File description:
** my_exec
*/
#include "../include/my.h"
#include "../include/include.h"

void my_exec(char *arg0, char *arg1)
{
    printf("Executing: %s\n", arg0);
    printf("Argument: %s\n", arg1);
    execlp(arg0, arg0, arg1, (char *)NULL);
    perror("execvp");
}
