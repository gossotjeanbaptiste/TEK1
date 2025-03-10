/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** my_put_ssize_t
*/
#include "my.h"
#include <unistd.h>

int my_put_ssize_t(ssize_t nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_ssize_t(nb / 10);
        my_put_ssize_t(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}
