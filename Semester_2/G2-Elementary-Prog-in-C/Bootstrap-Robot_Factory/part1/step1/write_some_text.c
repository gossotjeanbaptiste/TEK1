/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** write_some_text
*/
#include <stdio.h>

int write_some_text(void)
{
    FILE *fptr;

    fptr = fopen("some-text.yolo", "w+");
    if (!fptr)
        return 84;
    fprintf(fptr, "Hello bambino\n");
    fclose(fptr);
    return 0;
}

int main(void)
{
    if (write_some_text() == 84)
        return 84;
    return 0;
}
