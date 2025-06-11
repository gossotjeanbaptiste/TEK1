/*
** EPITECH PROJECT, 2025
** tes
** File description:
** ye
*/

#include "../include/lingo.h"

int read_guess(char **guess)
{
    size_t len = 0;
    ssize_t read = 0;

    read = getline(guess, &len, stdin);
    if (read != -1) {
        if ((*guess)[strlen(*guess) - 1] == '\n')
            (*guess)[strlen(*guess) - 1] = '\0';
    }
    return read;
}
