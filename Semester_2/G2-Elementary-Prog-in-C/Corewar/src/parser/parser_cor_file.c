/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** parser
*/

#include <stdlib.h>
#include "../../include/corewar.h"
#include "../../include/my.h"

static long calcul_sign(char const *str, long value)
{
    for (int j = 0; str[j] == '+' || str[j] == '-'; j++)
        if (str[j] == '-')
            value = value * -1;
    return (value);
}

static long my_getlongnbr(char const *str)
{
    long value = 0;
    int pos = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48 && str[i] != '-' && str[i] != '+') ||
        str[i] > 57 || (str[i] < 48 && pos == 1))
            return (calcul_sign(str, value));
        if (str[i] > 47 && str[i] < 58) {
            pos = 1;
            value = (value * 10) + (str[i] - 48);
        }
    }
    return (calcul_sign(str, value));
}

static void parse_prog_header(char *file, prog_t *prog)
{
    for (int i = 4; i < 4 + PROG_NAME_LENGTH; i++)
        prog->name[i - 4] = file[i];
    prog->name[PROG_NAME_LENGTH] = '\0';
    for (int i = 12 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH +
    COMMENT_LENGTH; i++)
        prog->comment[i - 12 - PROG_NAME_LENGTH] = file[i];
    prog->comment[COMMENT_LENGTH] = '\0';
    prog->size = file[4 + PROG_NAME_LENGTH];
    for (int i = 5 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH; i++) {
        prog->size = prog->size << 8;
        prog->size += file[i];
    }
}

static void verify_placing(global_t *global, prog_t *prog)
{
    if (prog->address == -1)
        return;
    if (!can_place_prog(global, prog, prog->address))
        return;
}

static void define_content(char *file, prog_t *new)
{
    new->content = malloc(sizeof(char) * new->size);
    for (int i = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH; i < 12 +
        PROG_NAME_LENGTH + COMMENT_LENGTH + new->size; i++)
        new->content[i - 12 - PROG_NAME_LENGTH - COMMENT_LENGTH] = file[i + 4];
}

void parse_cor_file(char *file, char *prog_nbr, char *load_address,
    global_t *global)
{
    prog_t *new = malloc(sizeof(prog_t));

    new->id = (prog_nbr == NULL) ? get_first_valid_id(global)
    : my_getlongnbr(prog_nbr);
    if (!is_prog_id_valid(global, new->id))
        return;
    new->address = (load_address == NULL) ? -1 : my_getnbr(load_address);
    new->carry = 0;
    new->live_call_cyle = 0;
    new->pc = 0;
    parse_prog_header(file, new);
    define_content(file, new);
    new->registers = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        new->registers[i] = 0;
    new->registers[0] = new->id;
    new->last_execute = -1;
    verify_placing(global, new);
    add_prog(global, new);
}
