/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** switch_base
*/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "my.h"


// Convertit un caractère en chiffre pour les bases
// (utilisé pour Hexadécimal et autres)
int char_to_digit(char c, int use_lowercase)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return (use_lowercase ? c - 'a' + 10 : c - 'A' + 10);
}

// Convertit un chiffre en caractère (A = 10, B = 11, etc.)
char digit_to_char(int digit, int use_lowercase)
{
    if (digit < 10)
        return '0' + digit;
    else
        return (use_lowercase ? 'a' : 'A') + (digit - 10);
}

// Convertit un nombre d'une base donnée en base 10
int to_base_10(char *number, int base, int use_lowercase)
{
    int length = my_strlen(number);
    int result = 0;
    int value = 0;

    for (int i = 0; i < length; i++) {
        value = char_to_digit(number[i], use_lowercase);
        if (value < 0 || value >= base) {
            my_putstr("Erreur : Caractère invalide pour la base");
            return -1;
        }
        result = result * base + value;
    }
    return result;
}

// Convertit un nombre en base 10 vers une autre base (binaire, octal, etc.)
void from_base_10(int number, int base, char *result, int use_lowercase)
{
    int index = 0;
    int remainder = 0;

    if (number == 0) {
        result[index] = '0';
        index++;
        result[index] = '\0';
        return;
    }
    while (number > 0) {
        remainder = number % base;
        result[index] = digit_to_char(remainder, use_lowercase);
        index++;
        number /= base;
    }
    result[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        swap_index(result, index, i);
    }
}

// Fonction principale pour convertir entre les bases spécifiées
void convert_base(char *number, int base_from, int base_to, int use_lowercase)
{
    char result[64];
    int decimal_value = to_base_10(number, base_from, use_lowercase);

    if (decimal_value == -1) {
        my_putstr("Conversion impossible.\n");
        return;
    }
    if (base_to == 10) {
        my_putstr(result);
        my_put_nbr(decimal_value);
    } else {
        from_base_10(decimal_value, base_to, result, use_lowercase);
    }
    my_putstr(result);
}
