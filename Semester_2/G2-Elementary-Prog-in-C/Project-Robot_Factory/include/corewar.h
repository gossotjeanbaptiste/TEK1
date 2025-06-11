/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** corewar
*/

#ifndef INCLUDED_COREWAR_H
    #define INCLUDED_COREWAR_H
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include "op.h"
    #define MAX_LINE 256
    #define MAX_NAME 128
    #define MAX_COMMENT 2048

void trim_newline(char *str);
void parse_header(FILE *file, header_t *header);
void parse_instructions(FILE *file);
char *label_finder(char line[MAX_LINE]);
int label_printer(int *found, char instr[MAX_LINE]);
void trim_leading_whitespace(char *str);
void trim_trailing_whitespace(char *str);
int assembly(header_t header, char *file_name);
int ends_with_s(const char *filename);
#endif /* !INCLUDED_COREWAR_H */
