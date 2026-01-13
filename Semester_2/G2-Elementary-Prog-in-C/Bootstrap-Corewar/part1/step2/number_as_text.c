/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** number_as_text
*/
#include <stdio.h>

int number_as_text(void)
{
    FILE *fptr;

    fptr = fopen("number-as-text.yolo", "w+");
    if (!fptr)
        return 84;
    fprintf(fptr, "12345678");
    fclose(fptr);
    return 0;
}

int main(void)
{
    if (number_as_text() == 84)
        return 84;
    return 0;
}
