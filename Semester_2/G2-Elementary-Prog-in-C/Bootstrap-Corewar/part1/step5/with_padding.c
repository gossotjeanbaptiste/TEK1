/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** with_padding
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int with_padding(void)
{
    FILE *file;
    data_t data = {192837, 'k', "Corewar is swag!!"};

    file = fopen("one-structure.yolo", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 84;
    }
    fwrite(&data, sizeof(data_t), 1, file);
    fclose(file);
    return 0;
}

int main(void)
{
    if (with_padding() == 84)
        return 84;
    return 0;
}
