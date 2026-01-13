/*
** EPITECH PROJECT, 2025
** TEXT_COUNT
** File description:
** header
*/

#ifndef TEXT_COUNT_H
    #define TEXT_COUNT_H

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #define RETURN_ERROR 84
    #define RETURN_SUCCESS 0

typedef struct {
    int flag_t;
    int flag_r;
} args_t;

typedef struct {
    char character;
    unsigned int count;
} char_t;

#endif
