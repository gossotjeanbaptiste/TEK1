/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** yolotron_asm
*/

#include "yolotron_asm.h"

void handler2(char instruction[10], FILE *output)
{
    if (my_strcmp(instruction, "sub") == 0) {
        fputc(0x02, output);
    } else if (my_strcmp(instruction, "mul") == 0) {
        fputc(0x03, output);
    }
}

int handler(FILE *input, char instruction[10], FILE *output)
{
    int param1;
    int param2;

    if (fscanf(input, "%d %d", &param1, &param2) != 2) {
        fprintf(stderr, "Error reading parameters\n");
        return 84;
    }
    if (my_strcmp(instruction, "add") == 0) {
        fputc(0x01, output);
    }
    handler2(instruction, output);
    fwrite(&param1, sizeof(int), 1, output);
    fwrite(&param2, sizeof(int), 1, output);
    return 0;
}

int compile(FILE *input, FILE *output)
{
    char instruction[10];
    char word[256];

    while (fscanf(input, "%s", instruction) != EOF) {
        if (compiler_condition(instruction, input, word, output) == 84)
            return 84;
    }
    return 0;
}

int compiler_condition(char instruction[10], FILE *input,
    char word[256], FILE *output)
{
    int length = 0;

    if (my_strcmp(instruction, "put") == 0) {
        if (fscanf(input, "%s", word) != 1) {
            fprintf(stderr, "Error reading string\n");
            return 84;
        }
        length = strlen(word);
        fputc(0x04, output);
        fwrite(&length, sizeof(int), 1, output);
        fwrite(word, sizeof(char), length, output);
    } else {
        if (handler(input, instruction, output) == 84)
            return 84;
    }
    return 0;
}
