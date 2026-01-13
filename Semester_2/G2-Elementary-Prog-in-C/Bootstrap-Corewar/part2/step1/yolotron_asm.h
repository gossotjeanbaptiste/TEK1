/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** yolotron_asm
*/

#ifndef INCLUDED_YOLOTRON_ASM_H
    #define INCLUDED_YOLOTRON_ASM_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../../include/my.h"
int annexe_main(char **argv);
void handler2(char instruction[10], FILE *output);
int handler(FILE *input, char instruction[10], FILE *output);
int compile(FILE *input, FILE *output);
int compiler_condition(char instruction[10], FILE *input,
    char word[256], FILE *output);
#endif
