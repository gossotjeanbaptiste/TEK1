/*
** EPITECH PROJECT, 2024
** CWorkshopLib
** File description:
** my_puthex
*/
#include "my.h"
#include <ctype.h>
#include <unistd.h>


// Fonction auxiliaire pour afficher un nombre en hexadécimal sur 2 caractères
void my_puthex2(unsigned char n)
{
    char hex_digits[] = "0123456789abcdef";
    char hex[2] = {hex_digits[(n >> 4) & 0xF], hex_digits[n & 0xF]};

    my_putstr(hex);
}

// Fonction auxiliaire pour afficher une adresse hexadécimale sur 8 caractères
void my_puthex8(int n)
{
    char hex_digits[] = "0123456789abcdef";
    char hex[8];

    for (int i = 7; i >= 0; i--) {
        hex[i] = hex_digits[n & 0xF];
        n >>= 4;
    }
    my_putstr(hex);
}
