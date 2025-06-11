/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** main
*/

#include "../include/graphic_art.h"
#include "../include/tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int which_digit(const char digit, const char character)
{
    if (digit == '0')
        return graph_zero(character);
    if (digit == '1')
        return graph_one(character);
    if (digit == '2')
        return graph_two(character);
    if (digit == '3')
        return graph_three(character);
    if (digit == '4')
        return graph_four(character);
    if (digit == '5')
        return graph_five(character);
    if (digit == '6')
        return graph_six(character);
    if (digit == '7')
        return graph_seven(character);
    if (digit == '8')
        return graph_eight(character);
    if (digit == '9')
        return graph_nine(character);
}

static int handle_errors(flag_t *flags, int ac)
{
    if (!flags->flag_n)
        return 1;
    if ((flags->flag_n || flags->flag_s) && ac % 2 != 1)
        return 1;
    return 0;
}

static void get_the_graphic_done(flag_t *flags)
{
    int len_s = 0;
    int len_n = strlen(flags->flag_n);
    int is_flag_s = (flags->flag_s) ? 1 : 0;

    for (int i = 0; i < len_n - 1; i++) {
        if (!is_flag_s)
            which_digit(flags->flag_n[i], '0');
        if (is_flag_s) {
            len_s = strlen(flags->flag_s);
            which_digit(flags->flag_n[i], 
                flags->flag_s[(flags->flag_n[i] - '0') % len_s]);
        }
        printf(" ");
    }
    if (is_flag_s)
        which_digit(flags->flag_n[len_n - 1], 
            flags->flag_s[(flags->flag_n[len_n - 1] - '0') % len_s]);
    else
        which_digit(flags->flag_n[len_n -1], '0');
    printf("\n");
}

int main(int ac, char const * const *av)
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
