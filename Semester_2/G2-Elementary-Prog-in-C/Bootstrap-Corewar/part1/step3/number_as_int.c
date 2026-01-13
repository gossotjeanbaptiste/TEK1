/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** number_as_int
*/
#include <stdio.h>

int number_as_text(void)
{
    FILE *fptr;
    int number = 12345678;

    fptr = fopen("number-as-int.yolo", "wb");
    if (!fptr)
        return 84;
    fwrite(&number, sizeof(int), 1, fptr);
    fclose(fptr);
    return 0;
}

int main(void)
{
    if (number_as_text() == 84)
        return 84;
    return 0;
}
