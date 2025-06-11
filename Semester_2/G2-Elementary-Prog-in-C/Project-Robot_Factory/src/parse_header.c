/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** parse_header
*/

#include "../include/my.h"
#include "../include/corewar.h"

static int parser2(char line[MAX_LINE], header_t *header)
{
    if (my_strncmp(line, "\t.comment", 8) == 0) {
        sscanf(line, "\t.comment \"%[^\"]\"", header->comment);
        return 0;
    } else if (my_strncmp(line, ".comment", 8) == 0) {
        sscanf(line, ".comment \"%[^\"]\"", header->comment);
        return 0;
    }
    if (line[0] != '#' && my_strlen(line) > 0) {
        return 84;
    }
    return 0;
}

static int parser(char line[MAX_LINE], header_t *header)
{
    if (my_strncmp(line, "\t.name", 5) == 0) {
        sscanf(line, "\t.name \"%[^\"]\"", header->prog_name);
        return 0;
    } else if (my_strncmp(line, ".name", 5) == 0) {
        sscanf(line, ".name \"%[^\"]\"", header->prog_name);
        return 0;
    }
    if (parser2(line, header) == 84) {
        return 84;
    }
    return 0;
}

void parse_header(FILE *file, header_t *header)
{
    char line[MAX_LINE];

    while (my_fgets(line, MAX_LINE, file)) {
        trim_newline(line);
        if (parser(line, header) == 84)
            break;
    }
}
