/*
** EPITECH PROJECT, 2025
** Epi-Template-C
** File description:
** asm
*/

#include "../include/my.h"
#include "../include/ansi_color_code.h"
#include "../include/corewar.h"
#include <sys/types.h>
#include <sys/stat.h>

static uint32_t inverser_octets(uint32_t nombre)
{
    return ((nombre & 0xFF000000) >> 24) |
    ((nombre & 0x00FF0000) >> 8) |
    ((nombre & 0x0000FF00) << 8) |
    ((nombre & 0x000000FF) << 24);
}

static char *file_cor(char *filename)
{
    size_t filename_len = my_strlen(filename);
    char *filename_cor = malloc(filename_len + 5);

    if (filename_cor == NULL) {
        return NULL;
    }
    my_strncpy(filename_cor, filename, filename_len - 1);
    my_strcpy(filename_cor + filename_len - 1, "cor");
    return filename_cor;
}

static int head_cor(header_t header, char *filename, FILE *output)
{
    struct stat file_stat;
    uint32_t reversed_magic;
    uint32_t reversed_prog_size;

    stat(filename, &file_stat);
    header.magic = COREWAR_EXEC_MAGIC;
    reversed_magic = inverser_octets(header.magic);
    header.prog_size = file_stat.st_size - sizeof(header_t);
    reversed_prog_size = inverser_octets(header.prog_size);
    if (!fwrite(&reversed_magic, sizeof(header.magic), 1, output) ||
    !fwrite(header.prog_name, sizeof(header.prog_name), 1, output) ||
    !fwrite("\0\0\0\0", 4, 1, output) ||
    !fwrite(&reversed_prog_size, sizeof(reversed_prog_size), 1, output) ||
    !fwrite(header.comment, sizeof(header.comment), 1, output) ||
    !fwrite("\0\0\0\0", 4, 1, output))
        return 84;
    return 0;
}

static int create_file_cor(header_t header, char *filename)
{
    char *filename_cor = file_cor(filename);
    FILE *output = fopen(filename_cor, "wb");

    if (head_cor(header, filename, output) == 84) {
        fclose(output);
        free(filename_cor);
        return 84;
    }
    fclose(output);
    free(filename_cor);
    return 0;
}

int assembly(header_t header, char *file_name)
{
    return create_file_cor(header, file_name);
}
