/*
** EPITECH PROJECT, 2025
** crocus
** File description:
** graphic_art header
*/

#ifndef GRAPHIC_ART_H_
    #define GRAPHIC_ART_H_

    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>

typedef struct flag_s {
    char *flag_n;
    char *flag_s;
}flag_t;

void handle_specifier(const int ac, const char *const av[],
    flag_t *flags);
#endif /* !GRAPHIC_ART_H_ */
