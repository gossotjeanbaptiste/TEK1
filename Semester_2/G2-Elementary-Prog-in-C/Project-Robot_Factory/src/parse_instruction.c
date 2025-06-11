/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** parser
*/


#include "../include/my.h"
#include "../include/corewar.h"
extern const op_t op_tab[];

void parse_instructions(FILE *file)
{
    char line[MAX_LINE];
    char instr[MAX_LINE];
    int found = 0;

    while (my_fgets(line, MAX_LINE, file)) {
        trim_newline(line);
        if (line[0] == '\0' || line[0] == COMMENT_CHAR)
            continue;
        label_finder(line);
        sscanf(line, "%s", instr);
        found = label_printer(&found, instr);
        if (!found && instr[0] != '\0') {
            mini_printf("Error: Unknown instruction %s\n", instr);
        }
    }
}
