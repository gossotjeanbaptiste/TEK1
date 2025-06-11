/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** yolotron_vm
*/
#include "yolotron_vm.h"

int main(int argc, char *argv[])
{
    FILE *input = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <compiled yolotron file>\n", argv[0]);
        return 84;
    }
    input = fopen(argv[1], "rb");
    if (!input) {
        perror("Failed to open input file");
        return 84;
    }
    while (!feof(input)) {
        if (execute_instruction(input) == 84) {
            fclose(input);
            return 84;
        }
    }
    fclose(input);
    return 0;
}

int execute_default(void)
{
    fprintf(stderr, "ahhhh no, don't agree!\n");
    return 84;
}

int execute_instruction(FILE *input)
{
    int instruction = fgetc(input);
    int param1 = 0;
    int param2 = 0;
    int length = 0;

    if (instruction == EOF)
        return 0;
    switch (instruction) {
        case 0x01:
            return execute_add(input, param1, param2);
        case 0x02:
            return execute_sub(input, param1, param2);
        case 0x03:
            return execute_mul(input, param1, param2);
        case 0x04:
            return execute_put(input, length);
        default:
            return execute_default();
    }
}
