/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** dump_arg
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/corewar.h"

static char *my_addchar(char *str, char c, int position)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    if (position) {
        result[0] = c;
        for (; str[i] != '\0'; i++)
            result[i + 1] = str[i];
    } else {
        result[my_strlen(str)] = c;
        for (; str[i] != '\0'; i++)
            result[i] = str[i];
        i += 1;
    }
    result[i + 1] = '\0';
    free(str);
    return result;
}

static long long get_basic_value(char c, char *base)
{
    for (int i = 0; base[i] != '\0'; i++) {
        if (c == base[i])
            return i;
    }
    return 0;
}

static long long put_base_ten(char *nbr, char *base_from)
{
    long long calcul = 0;
    long long pow = 1;

    for (int i = my_strlen(nbr) - 1; i >= 0; i--) {
        calcul += get_basic_value(nbr[i], base_from) * pow;
        pow *= my_strlen(base_from);
    }
    return calcul;
}

static char *put_base_other(long long nb, char *base_to)
{
    char *result = malloc(sizeof(char));
    int calcul;

    result[0] = '\0';
    while (nb > 0) {
        calcul = nb % my_strlen(base_to);
        result = my_addchar(result, base_to[calcul], 1);
        nb = nb / my_strlen(base_to);
    }
    return result;
}

static char *my_convert_base(char *nbr, char *base_from, char *base_to)
{
    long long base_ten;
    char *result;

    if (my_strcmp(base_from, base_to) == 0)
        return (nbr);
    base_ten = put_base_ten(nbr, base_from);
    result = put_base_other(base_ten, base_to);
    return (result);
}

void manage_dump_arg(char *value, args_infos_t *infos)
{
    long cycles = 0;
    char *base_ten;

    for (int i = 0; value[i] != '\0'; i++) {
        if (!((value[i] >= 'A' && value[i] <= 'F') ||
        (value[i] >= '0' && value[i] <= '9')))
            return;
    }
    base_ten = my_convert_base(value, "0123456789ABCDEF", "0123456789");
    cycles = my_getnbr(base_ten);
    free(base_ten);
    if (cycles <= 0)
        return;
    if (infos->dump != NULL)
        free(infos->dump);
    infos->dump = my_strdup(value);
    infos->global->nbr_cycle_dump = cycles;
}
