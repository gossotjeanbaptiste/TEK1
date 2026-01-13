/*
** EPITECH PROJECT, 2025
** Bootstrap-Corewar
** File description:
** your_binary_calling_your_function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction qui décode un octet de codage et affiche les types de paramètres
void decode_coding_byte(unsigned char coding_byte)
{
    const char *param_types[] = {"", "register", "direct", "indirect"};
    unsigned char param;

    printf("For value: 0x%02x\n", coding_byte);
    for (int i = 0; i < 4; i++) {
        param = (coding_byte >> (6 - i * 2)) & 0x03;
        printf("%d: %02d -> ", i + 1, param);
        if (param >= 0 && param <= 3)
            printf("%s\n", param_types[param]);
        else
            printf("unknown\n");
    }
}

int main(int argc, char **argv)
{
    unsigned char coding_byte;
    char *endptr;

    if (argc > 1) {
        if (strncmp(argv[1], "0x", 2) == 0 || strncmp(argv[1], "0X", 2) == 0)
            coding_byte = (unsigned char)strtol(argv[1], &endptr, 16);
        else
            coding_byte = (unsigned char)strtol(argv[1], &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "Error: Invalid input format\n");
            return 84;
        }
    }
    decode_coding_byte(coding_byte);
    return 0;
}
