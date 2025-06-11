/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** main
*/

#include "../include/graphic_art.h"
#include <stdlib.h>

const char *digits[10][5] = {
    {" 000 ", "0   0", "0   0", "0   0", " 000 "},
    {" 000 ", "0 00 ", "  00 ", "  00 ", " 0000"},
    {" 000 ", "0   0", "   0 ", " 0   ", "00000"},
    {"0000 ", "    0", " 000 ", "    0", "0000 "},
    {"  00 ", " 0 0 ", "0  0 ", "00000", "   0 "},
    {"00000", "0    ", "0000 ", "    0", "0000 "},
    {" 000 ", "0    ", "0000 ", "0   0", " 000 "},
    {"00000", "    0", "   0 ", "  0  ", " 0   "},
    {" 000 ", "0   0", " 000 ", "0   0", " 000 "},
    {" 000 ", "0   0", " 0000", "    0", " 000 "}
};

static int handle_errors(const flag_t *flags, int ac)
{
    if (!flags->flag_n)
        return 1;
    if ((flags->flag_n || flags->flag_s) && ac % 2 != 1)
        return 1;
    return 0;
}

static void print_another_char(const char new,
    const char *to_print)
{
    const int len = strlen(to_print);

    for (int i = 0; i < len; i++)
        if (to_print[i] == '0')
            printf("%c", new);
        else
            printf(" ");
}

static void print_graphic(const flag_t *flags, const int i,
    const int j, const int len_n)
{
    int len_s = 0;

    if (flags->flag_s && flags->flag_s[0]) {
        len_s = strlen(flags->flag_s);
        print_another_char(flags->flag_s[(flags->flag_n[j] - '0') % len_s],
            digits[flags->flag_n[j] - '0'][i]);
    } else
        printf("%s", digits[flags->flag_n[j] - '0'][i]);
    if (j < len_n - 1)
        printf(" ");
}

static void get_the_graphic_done(const flag_t *flags)
{
    const int len_n = strlen(flags->flag_n);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < len_n; j++) {
            print_graphic(flags, i, j, len_n);
        }
        printf("\n");
    }
}

int main(int ac, const char *const av[])
{
    flag_t *flags = malloc(sizeof(flag_t));

    if (!flags)
        return 84;
    handle_specifier(ac, av, flags);
    if (handle_errors(flags, ac))
        return 84;
    get_the_graphic_done(flags);
    free(flags);
    return 0;
}
