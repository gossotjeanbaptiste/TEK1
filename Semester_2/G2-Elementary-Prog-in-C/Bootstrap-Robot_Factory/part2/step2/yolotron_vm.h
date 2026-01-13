/*
** EPITECH PROJECT, 2025
** Bootstrap-Robot_Factory
** File description:
** yolotron_vm
*/

#ifndef INCLUDED_YOLOTRON_VM_H
    #define INCLUDED_YOLOTRON_VM_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
int execute_instruction(FILE *input);
int execute_default(void);
int execute_add(FILE *input, int param1, int param2);
int execute_sub(FILE *input, int param1, int param2);
int execute_mul(FILE *input, int param1, int param2);
int execute_put(FILE *input, int length);
#endif /* !INCLUDED_YOLOTRON_VM_H */
