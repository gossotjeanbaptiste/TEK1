/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** without_padding
*/
#include <stdio.h>

int without_padding(void)
{
    FILE *file;
    int number = 192837;
    char character = 'k';
    char string[40] = "Corewar is swag!!";

    file = fopen("several-variables.yolo", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 84;
    }
    fwrite(&number, sizeof(int), 1, file);
    fwrite(&character, sizeof(char), 1, file);
    fwrite(string, sizeof(char), 40, file);
    fclose(file);
    return 0;
}

int main(void)
{
    if (without_padding() == 84)
        return 84;
    return 0;
}
