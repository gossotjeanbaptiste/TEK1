/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** main
*/
#include "yolotron_asm.h"

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 0;
    }
    if (annexe_main(argv) == 84)
        return 84;
    return 0;
}

int annexe_main(char **argv)
{
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "wb");

    if (!input) {
        perror("Failed to open input file");
        return 84;
    }
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        return 84;
    }
    if (compile(input, output) == 84)
        return 84;
    fclose(input);
    fclose(output);
    return 0;
}
