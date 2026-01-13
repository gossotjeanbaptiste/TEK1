/*
** EPITECH PROJECT, 2024
** Project-my_top
** File description:
** unit_converter
*/

#include "../include/my.h"
#include "../include/call.h"

double convert(double value, unit_t from, unit_t to)
{
    static const double conversion_factors[] = {
        1.0,
        1024.0,
        1024.0 * 1024.0,
        1024.0 * 1024.0 * 1024.0,
        1024.0 * 1024.0 * 1024.0 * 1024.0,
        1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0,
        1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0
    };
    double value_in_bytes = value * conversion_factors[from];

    return value_in_bytes / conversion_factors[to];
}
