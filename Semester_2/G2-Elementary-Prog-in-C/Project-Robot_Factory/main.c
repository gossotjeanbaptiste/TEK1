/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** Main for Epi-Template-C
*/
#include "include/my.h"
#include "include/corewar.h"


int main(int argc, char **argv)
{
    header_t header = {.prog_name = "", .comment = ""};
    FILE *file = fopen(argv[1], "r");

    if (argc != 2 || ends_with_s(argv[1]) != 0) {
        mini_printf("Usage: %s <file.s>\n", argv[0]);
        return 84;
    }
    if (!file) {
        mini_printf("Error opening file");
        return 84;
    }
    parse_header(file, &header);
    mini_printf("Parsed Name: %s\nParsed Comment: %s\n",
        header.prog_name, header.comment);
    parse_instructions(file);
    fclose(file);
    assembly(header, argv[1]);
    return 0;
}
