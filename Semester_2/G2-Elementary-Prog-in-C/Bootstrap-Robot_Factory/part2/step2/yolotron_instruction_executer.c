/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** yolotron_instruction_executer
*/
#include "yolotron_vm.h"

int execute_add(FILE *input, int param1, int param2)
{
    if (fread(&param1, sizeof(int), 1, input) != 1) {
        perror("fread failed");
        return 84;
    }
    if (fread(&param2, sizeof(int), 1, input) != 1) {
        perror("fread failed");
        return 84;
    }
    printf("add %d %d = %d\n", param1, param2, param1 + param2);
    return 0;
}

int execute_sub(FILE *input, int param1, int param2)
{
    if (fread(&param1, sizeof(int), 1, input) != 1) {
        perror("fread failed");
        return 84;
    }
    if (fread(&param2, sizeof(int), 1, input) != 1) {
        perror("fread failed");
        return 84;
    }
    printf("sub %d %d = %d\n", param1, param2, param1 - param2);
    return 0;
}

int execute_mul(FILE *input, int param1, int param2)
{
    if (fread(&param1, sizeof(int), 1, input) != 1) {
        perror("fread failed");
        return 84;
    }
    if (fread(&param2, sizeof(int), 1, input) != 1) {
        perror("fread failed");
        return 84;
    }
    printf("mul %d %d = %d\n", param1, param2, param1 * param2);
    return 0;
}

int execute_put(FILE *input, int length)
{
    char *word = NULL;

    if (fread(&length, sizeof(int), 1, input) != 1) {
        perror("fread failed");
        return 84;
    }
    word = malloc(length + 1);
    if (word == NULL) {
        perror("malloc failed");
        return 84;
    }
    if (fread(word, sizeof(char), length, input) != (size_t)length) {
        perror("fread failed");
        free(word);
        return 84;
    }
    word[length] = '\0';
    printf("put %s\n", word);
    free(word);
    return 0;
}
